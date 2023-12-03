def deep():
    answer = (input("What is the answer to the Great Question of Life, the Universe and Everything? \n").lower().strip())
    if answer == "42" or answer == "forty-two" or answer == "forty two" or answer == "fortytwo":
        print("Yes")
    else:
        print("No")
    return
deep()