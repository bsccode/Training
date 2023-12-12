largest = None
smallest = None
while True:
    num = input("Enter a number: ")
    if num == "done":
        break
    try:
        num = int(num)
    except:
        print("Invalid input")
        continue
    try:
        largest = int(largest)
    except:
        largest = num
    if num >= largest :
        largest = num
    try:
        smallest = int(smallest)
    except:
        smallest = num
    if num <= smallest :
        smallest = num

print("Maximum is", largest)
print("Minimum is", smallest)