def greeting():
    greet = input("Please greet me! \n").lower().strip()
    if "hello" in greet:
        value = 0
    elif greet.startswith("h") == True:
        value = 20
    else:
        value = 100
    return print("$" + str(value))
greeting()