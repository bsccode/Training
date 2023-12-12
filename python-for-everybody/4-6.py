def computepay(h, r):
    h = h
    rate = r
    rateAbove40 = rate * 1.5
    overTime = h - 40
    if overTime < 0:
        overTime = 0
    else: overTime = overTime
    amountEarned = (h - overTime) * rate
    oVertimeEarned= overTime * rateAbove40
    Total= amountEarned + oVertimeEarned

    return (Total)
    
    
 
h = float(input("Enter Hours: ")) 
r = float(input("Enter Rate: "))
p = computepay(h, r)
print("Pay " + str(p))

