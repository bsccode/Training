import random

def hello():
    print("\n Welcome to the Robot VS Human Fight simulator\n")
    return

def speedfunction():
    seconds = int(input("Please enter how many seconds it took for your robot to complete the race.\n"))
    distance = int(input("Please enter how many meters the race was completed over\n"))
    speed = distance / seconds
    return speed

def strengthfunction():
    strength = int(input("How many objects did your robot lift between 0-100?\n"))
    return strength

def combatcalc(speed,strength):
    combatmin = speed+strength/100*50-10
    combatminvalue = max(combatmin, 0)
    combatmax = speed+strength/100*50+10
    combatmaxvalue = min(combatmax, 100)
    print("Your Robot has between " + str(combatminvalue) + " and " + str(combatmaxvalue) + "% chance of winning. Good Luck!\n") 
    cont = int(input("Please press 1 to continue the simulation\n" ))
    return combatmaxvalue

def combat(combatmaxvalue):
    human = 0
    robot = 0
    for i in range(0,100):
        aifight=random.randint(0,100)
        if aifight > combatmaxvalue:
            print("Robot Win!")
            robot += 1
        else: 
            print("Human Win!")
            human += 1
    return human,robot

hello()
speed = speedfunction()
strength = strengthfunction()
combatmaxvalue = combatcalc(speed,strength)
human,robot = combat(combatmaxvalue)

print("The Robot won "+ str(robot) + " times and the hoomans won " + str(human) + " times!\n")
print("Your speed score is " + str(speed) + "\n")
print("Your strength score is " + str(strength) + "\n")
print("Your combat strength is " + str(combatmaxvalue) + "\n")





