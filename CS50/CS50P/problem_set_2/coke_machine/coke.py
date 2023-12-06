def coke():
    coins =  0
    total_coins = 0
    while total_coins < 50:
        coins = int(input("Insert Coin: "))
        if coins == 5 or coins == 10 or coins == 25 or coins == 50:
            total_coins += coins
            print("Amount Due: " + str(50 - total_coins))
        else:
            print("Amount Due: " + str(50 - total_coins))
    change = total_coins - 50
    print("Change Owed: " + str(change))
coke()


