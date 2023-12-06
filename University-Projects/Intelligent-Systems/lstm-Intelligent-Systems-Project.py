import torch
import torch.nn as nn
import torch.optim as optim
from torch.utils.data import DataLoader, TensorDataset
import pandas as pd
import seaborn as sns
from sklearn.preprocessing import LabelEncoder, MinMaxScaler
from sklearn.metrics import classification_report
from sklearn.metrics import confusion_matrix, roc_curve, auc
from sklearn import datasets
from sklearn.model_selection import train_test_split
import numpy as np
import matplotlib.pyplot as plt

# Load and Preprocess the Data
data = pd.read_csv('kdd99.csv', header=0)
# Assume the last column is the target and the rest are features
X = data.drop(columns=['label'])
y = data['label']

# One-hot encode the categorical columns
X = pd.get_dummies(X, columns=['protocol_type', 'service', 'flag'])

# Encode labels
encoder = LabelEncoder()
y_encoded = encoder.fit_transform(y)

# Scale the features
scaler = MinMaxScaler()
X_scaled = scaler.fit_transform(X)

# Split the data into training and temporary sets (80% training, 20% temporary)
X_train, X_temp, y_train, y_temp = train_test_split(X_scaled, y_encoded, test_size=0.2, random_state=42)

# Split the temporary set into validation and testing sets (50% validation, 50% testing)
X_val, X_test, y_val, y_test = train_test_split(X_temp, y_temp, test_size=0.5, random_state=42)

# Convert to PyTorch tensors
X_tensor = torch.tensor(X_scaled, dtype=torch.float32)
y_tensor = torch.tensor(y_encoded, dtype=torch.long)
X_train_tensor = torch.tensor(X_train, dtype=torch.float32)
y_train_tensor = torch.tensor(y_train, dtype=torch.long)
X_val_tensor = torch.tensor(X_val, dtype=torch.float32)
y_val_tensor = torch.tensor(y_val, dtype=torch.long)
X_test_tensor = torch.tensor(X_test, dtype=torch.float32)
y_test_tensor = torch.tensor(y_test, dtype=torch.long)

dataset = TensorDataset(X_tensor, y_tensor)
dataloader = DataLoader(dataset, batch_size=64, shuffle=True)

# Define the LSTM Network
class LSTMNetwork(nn.Module):
    def __init__(self, input_size, hidden_size, num_layers, num_classes):
        super(LSTMNetwork, self).__init__()
        self.hidden_size = hidden_size
        self.num_layers = num_layers
        self.lstm = nn.LSTM(input_size, hidden_size, num_layers, batch_first=True)
        self.fc = nn.Linear(hidden_size, num_classes)

    def forward(self, x):
        h0 = torch.zeros(self.num_layers, x.size(0), self.hidden_size).to(x.device)
        c0 = torch.zeros(self.num_layers, x.size(0), self.hidden_size).to(x.device)
        out, _ = self.lstm(x, (h0, c0))
        out = self.fc(out[:, -1, :])
        return out

# Prepare DataLoaders
train_dataset = TensorDataset(X_train_tensor, y_train_tensor)
train_dataloader = DataLoader(train_dataset, batch_size=64, shuffle=True)

val_dataset = TensorDataset(X_val_tensor, y_val_tensor)
val_dataloader = DataLoader(val_dataset, batch_size=64, shuffle=False)

test_dataset = TensorDataset(X_test_tensor, y_test_tensor)
test_dataloader = DataLoader(test_dataset, batch_size=64, shuffle=False)

# Initialize and Train the Model
input_size = X_train.shape[1]
hidden_size = 128
num_layers = 2
num_classes = len(set(y_encoded))
model = LSTMNetwork(input_size, hidden_size, num_layers, num_classes)

criterion = nn.CrossEntropyLoss()
optimizer = optim.Adam(model.parameters(), lr=0.001)

loss_values = []
accuracy_values_val = []
accuracy_values_test = []

num_epochs = 1
for epoch in range(num_epochs):
    model.train()  # Set the model to training mode
    for batch_X, batch_y in train_dataloader:
        batch_X = batch_X.unsqueeze(1)  
        outputs = model(batch_X)
        optimizer.zero_grad()
        loss = criterion(outputs, batch_y)
        loss.backward()
        optimizer.step()
    loss_values.append(loss.item())  # Storing loss values

    # Evaluate the Model on Validation Set
    model.eval()
    with torch.no_grad():
        correct = 0
        total = 0
        for batch_X, batch_y in val_dataloader:
            batch_X = batch_X.unsqueeze(1)  
            outputs = model(batch_X)
            _, predicted = torch.max(outputs.data, 1)
            total += batch_y.size(0)
            correct += (predicted == batch_y).sum().item()
        accuracy_values_val.append(100 * correct / total)

    print(f'Epoch [{epoch+1}/{num_epochs}], Loss: {loss.item():.4f}, Validation Accuracy: {100 * correct / total:.2f}%')

# Evaluate the Model on Test Set
model.eval()
with torch.no_grad():
    correct = 0
    total = 0
    all_predicted = []
    all_labels = []  
    for batch_X, batch_y in test_dataloader:
        batch_X = batch_X.unsqueeze(1)  
        outputs = model(batch_X)
        _, predicted = torch.max(outputs.data, 1)
        all_predicted.extend(predicted.cpu().numpy())
        all_labels.extend(batch_y.cpu().numpy())
        total += batch_y.size(0)
        correct += (predicted == batch_y).sum().item()
    accuracy_values_test.append(100 * correct / total)

print('Test Accuracy: {}%'.format(100 * correct / total))

# Plot Loss over Epochs
plt.figure()
plt.plot(range(1, num_epochs + 1), loss_values, marker='o')
plt.title('Loss over Epochs')
plt.xlabel('Epochs')
plt.ylabel('Loss')
plt.grid(True)
plt.show()

# Plot Accuracy over Epochs
plt.figure()
plt.plot(range(1, num_epochs + 1), accuracy_values_val, marker='o', label='Validation Accuracy')
plt.plot(range(1, num_epochs + 1), [accuracy_values_test[0]]*num_epochs, marker='o', label='Test Accuracy')  
plt.title('Accuracy over Epochs')
plt.xlabel('Epochs')
plt.ylabel('Accuracy')
plt.legend()
plt.grid(True)
plt.show()

# Additional Evaluation Metrics on Test Set
print(confusion_matrix(all_labels, all_predicted))
print(classification_report(all_labels, all_predicted))

# Confusion Matrix
unique_labels = encoder.classes_
conf_matrix = confusion_matrix(all_labels, all_predicted, labels=range(len(unique_labels)))

# Use encoder.classes_ to ensure consistent labeling
class_labels = encoder.classes_

df_cm = pd.DataFrame(conf_matrix, index=[i for i in unique_labels],
                     columns=[i for i in unique_labels])
plt.figure(figsize=(10, 7))
sns.heatmap(df_cm, annot=True, fmt='d')
plt.title('Confusion Matrix')
plt.xlabel('Actual')
plt.ylabel('Predicted')
plt.show()
