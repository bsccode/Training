#Imported random module for random.randint()
# 5 functions

import random

#Greeting Function

def hello():
    print("\n Welcome to the Robot VS Human Fight simulator\n")
    return

#Function to input and calculated speed score

def speedfunction():
    seconds = -1  
    distance = -1 
    while seconds <= 0:
        inputseconds = input("Please enter how many seconds it took for your robot to complete the race: ")
        while not inputseconds.isdigit():
            inputseconds = input("Error. Please input a whole number: ")
        seconds = int(inputseconds)
        if seconds > 0:
            continue

    while distance <= 0:
        inputdistance = input("Please enter how many meters the race was completed over: ")
        while not inputdistance.isdigit():
            inputdistance = input("Error. Please input a whole number: ")
        distance = int(inputdistance)
        if distance > 0:
            continue
    speed = distance / seconds
    return speed

#Function to calculate strength score

def strengthfunction():
    strength = -1
    while strength < 0 or strength > 100:
        inputstrength = input("How many objects did your robot lift between 0-100?\n")
        while not inputstrength.isdigit():
            inputstrength = input("Error. Please input a whole number between 0-100: ")
        strength = int(inputstrength)
        if strength <= 0 and strength < 100:
            continue
    return strength

#function to calculate combat score using speed, strength and min/max value ranges

def combatcalc(speed,strength):
    combatmin = speed+strength/100*50-10
    combatminvalue = max(combatmin, 0)
    combatmax = speed+strength/100*50+10
    combatmaxvalue = min(combatmax, 100)
    print("Your Robot has between " + str(combatminvalue) + " and " + str(combatmaxvalue) + "% chance of winning. Good Luck!\n") 
    cont = int(input("Please press 1 to continue the simulation\n" ))
    while not cont == 1:
        cont = int(input("My Programmer is bad so I will only accept 1"))
        if cont == 1:
            continue
    return combatmaxvalue

#combat function using max combat value and applying a random number between 0-100 to "simulate" fighting

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

#the program as it runs and calls functions

hello()
speed = speedfunction()
strength = strengthfunction()
combatmaxvalue = combatcalc(speed,strength)
human,robot = combat(combatmaxvalue)

#Last Parts of the program that state the wins and losses and each score that was calculated

print("The Robot won "+ str(robot) + " times and the Humans won " + str(human) + " times!\n")
print("Your speed score is " + str(speed) + "\n")
print("Your strength score is " + str(strength) + "\n")
print("Your combat strength is " + str(combatmaxvalue) + "\n")





