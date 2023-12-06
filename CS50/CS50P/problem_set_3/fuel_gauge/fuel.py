#prompt user for a fraction
#formatted as X/Y
#X and Y will only be int
#outputs a percentage of the fraction to nearest int
#if less than 1% then ooutput E
#if more than 99 then output F
#if X or Y are not integer or X is greater than Y or Y is 0 prompt user again
#Catch Value error and zerodivisionerror

def fuel():
    while True:
        try:
            x,y = input("Fraction: ").split("/")
            x = int(x)
            y = int(y)
            decimal = (round((x/y)*100))
            if x > y:
                pass
            elif y == 0:
                pass
            elif decimal >= 99:
                print("F")
                break
            elif decimal <= 1:
                print("E")
                break
            else:
                print("%s%%"%decimal)
                break
        except:
            pass

fuel()
