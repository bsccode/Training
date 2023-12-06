def slow():
    sentence = input("Write a sentence for me Speedy. \n")
    slower = sentence.replace(" ","...")
    return print(slower)
slow()