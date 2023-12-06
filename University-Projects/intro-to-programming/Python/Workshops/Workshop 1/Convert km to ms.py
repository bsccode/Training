# Workshop 1 Code
# Make a converter from km/h to m/s

print("Please type your speed in Kilometers per hour\n")
km = int(input())
m = (km * 1000) / 3600
mps = round(m, 2)
print("you ae travelling at " + str(mps) + " meters per second!\n")
print("Thats so quick dude\n")
print("You should really slow down\n")
