# Use the file name mbox-short.txt as the file name
fname = input("Enter file name: ")
fhandle = open(fname)
count =0
total =0.0
for line in fhandle:
    if line.startswith('X-DSPAM-Confidence: '):
        value = float(line.split(':')[1])
        total += value
        count += 1
average = total / count
print('Average spam confidence:', average)
fhandle.close()
