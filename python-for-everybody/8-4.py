fname = input("Enter file name: ")
fh = open(fname)
lst = list()
for line in fh:
    words = line.split()
    for word in words:
        lst.append(word)

unique_lst = list()
for item in lst:
    if item not in unique_lst:
        unique_lst.append(item)
unique_lst.sort()
print(unique_lst)