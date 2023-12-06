def twttr():
    twttr_word = ""
    sentence = input("Input: ")
    for i in sentence:
        if i.lower() == "a" or i.lower() == "e" or i.lower() == "i" or i.lower() == "o" or i.lower() == "u":
            twttr_word += ""
        else: twttr_word += i
    print(twttr_word)
twttr()
