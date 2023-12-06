def math():
    equation = input("please tell me your math equation in the form of 'x y z' \n").strip()
    xraw, yraw, zraw = equation.split(" ")
    x = float(xraw)
    z = float(zraw)
    y = yraw.lower()
    if y == "-":
        sum = x - z
    elif y == "+":
        sum = x+z
    elif y == "/":
        sum = x/z
    elif y == "*" or "x":
        sum = x*z
    else:
        sum = ("sum is not valid for this calculator")
    print(str(sum))
    return sum

math()