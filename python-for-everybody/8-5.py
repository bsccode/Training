fname = input("Enter file name: ")
if len(fname) < 1:
    fname = "mbox-short.txt"

fh = open(fname)
count = 0
lst = list()
unique_lst = list()
for line in fh:
    if line.startswith('From '):
        lst.append(line)
for line in lst:
    unique_lst.append(line.split()[1])
    print(unique_lst[count])
    count += 1

print("There were", count, "lines in the file with From as the first word")
