"""def spin_words(sentence):
    list = sentence.split()
    for i in list:    
        if len(i) >= 5:
            txt = i[::-1]
            list[i] = txt
    return  print(" ".join(str(list)))

spin_words("hello how are youuu")
spin_words("hell")
spin_words("helloooooooo")"""

def spin_words(sentence):
    word_list = sentence.split()
    for i, word in enumerate(word_list):
        if len(word) >= 5:
            word_list[i] = word[::-1]
    return " ".join(word_list)

print(spin_words("hello how are youuu"))
print(spin_words("hell"))
print(spin_words("helloooooooo"))
