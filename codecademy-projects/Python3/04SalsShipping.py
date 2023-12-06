

#Ask user for weight of package and determine which method of shipping is cheapest and the cost of shipping

cost = 0
weight = 8.4
dronecost = 0
weightdrone = 1.5

if weight <= 2:
  cost=1.5 * weight + 20
elif weight <= 6:
  cost= 3 * weight + 20
elif weight <= 10:
  cost = 4 * weight+20
elif weight > 10:
  cost = 4.75 * weight + 20

print (cost)

print("\n if you want premium it will cost ya, 125 dollarydoos \n")

# drone shipping

if weightdrone <= 2:
  dronecost = 4.50 * weightdrone
elif weightdrone <= 6:
  dronecost = 9 * weightdrone
elif weightdrone <= 10:
  dronecost = 12 * weightdrone
elif weightdrone > 10:
  dronecost = 14.25 * weightdrone

print (dronecost)
