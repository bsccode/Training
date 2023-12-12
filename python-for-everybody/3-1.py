hrs = input("Enter Hours:")
h = float(hrs)
rate = float(input("enter rate: "))
rateAbove40 = rate * 1.5
overTime = h - 40
if overTime < 0:
    overTime = 0
else: overTime = overTime
amountEarned = (h - overTime) * rate
oVertimeEarned= overTime * rateAbove40
Total= amountEarned + oVertimeEarned

print(Total)