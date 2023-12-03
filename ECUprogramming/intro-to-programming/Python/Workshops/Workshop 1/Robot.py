
# Stated Loop Variable

quit = 1
while quit == 1:
    
    # Variables reset for new loop
    
    seconds = 0
    distance = 0
    
    # While loops for input with error correction if input is not a posistive int for both distance and time
    
    while seconds <= 0:
        inputseconds = input("Please enter how many seconds it took for the competitor to complete the race: ")
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
    
    # Mathematics calculations
    
    rawspeed = distance / seconds

#Round float to 2 decimal places

    speed = round(rawspeed, 2)

# Print Results

    print("Your competitor completed the race at an average of " + str(speed) + " meters per second\n")
    print("Congratulations that was pretty fast!\n")
    print("Do you want to restart the calculation?\n")
    
    # initiate loop, if input is NOT integer 1 then program will terminate
    # if input IS int 1 then program will loop
    
    print("Press 1 to restart, any other input will terminate this program")
    inputquit = input()
    while not inputquit.isdigit():
            inputquit = input("Error. Please input a whole number: ")
    quit = int(inputquit)
    if quit != 1:
        break