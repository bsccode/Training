name = input("Enter file:")
if len(name) < 1:
    name = "mbox-short.txt"
handle = open(name)

#max mail messages
# "From " second word
# dict key=address, value = number of emails
#max loop to count highest value

count = 0
lst = list()
for line in handle:
    if line.startswith('From '):
        lst.append(line.split()[1])
        
dic = dict()
for line in lst:
    dic[line] = dic.get(line,0) + 1
    
bigcount = None
bigword = None
for word,count in dic.items():
    if bigcount is None or count > bigcount:
        bigword = word
        bigcount = count
print(bigword, bigcount)
