# AI Project: LSTM Network for Network Intrusion Detection

## Project Overview

This project entails the development of a Long Short-Term Memory (LSTM) Neural Network model to identify network intrusions. The model is trained and evaluated using the KDD Cup 1999 dataset, a widely used data set in the field of network intrusion detection.

## Data Preparation and Preprocessing

- **Data Source**: `kdd99.csv`

- **Preprocessing Steps**:
  - Drop 'label' column from features (X)
  - One-hot encode categorical columns
  - Label encode the target variable
  - Scale features using MinMaxScaler
  - Split the dataset into training (80%), validation (10%), and testing (10%)

## LSTM Network Architecture

- **Model**: LSTMNetwork (PyTorch nn.Module)

- **Components**:
  - LSTM layer (configurable hidden size and number of layers)
  - Fully connected output layer

- **Parameters**: Input size, hidden layer size (128), number of layers (2), number of classes

## Training and Validation

- **Optimizer**: Adam (Learning rate: 0.001)
- **Loss Function**: CrossEntropyLoss
- **Batch Size**: 64
- **Epochs**: 1 (Configurable)
- **Metrics**: Loss, Validation Accuracy

## Testing and Evaluation

- **Test Accuracy Calculation**
- **Additional Metrics**: Confusion Matrix, Classification Report

- **Visualization**:
  - Loss over Epochs
  - Accuracy (Validation and Test) over Epochs
  - Confusion Matrix Heatmap

## Key Libraries and Frameworks
- PyTorch (model building and training)
- Pandas and Seaborn (data manipulation and visualization)
- Scikit-learn (data preprocessing and evaluation metrics)

## How to Run the Project

1. Ensure Python with required libraries (`torch`, `pandas`, `seaborn`, `sklearn`, `numpy`, `matplotlib`) is installed.
2. Place `kdd99.csv` in the project directory.
3. Run the script to train, evaluate, and visualize the model's performance.

## Conclusion

This project showcases LSTM networks' application in network security, particularly for intrusion detection, emphasizing preprocessing steps for handling data and LSTM's utility in sequence-based predictions in security contexts.
