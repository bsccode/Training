def create_phone_number(n):
    one = []
    two = []
    three = []
    for i in n[0:3]:
        one.append(i)
    for j in n[2:5]:
        two.append(j)
    for k in n[5:]:
        three.append(k)
    phone = "(" +("".join(map(str, one))) + ") " + ("".join(map(str, two))) + "-" + ("".join(map(str, three)))
    return phone

print(create_phone_number([1,2,3,4,5,6,7,8,9,3]))