def camel():
    name = input("Please Enter: ")
    print("snake_case: ", end="")
    for i in name:
        if i == i.upper():
            print("_" + i.lower(), end="")
        else:
            print(i, end="")
    print()


camel()
