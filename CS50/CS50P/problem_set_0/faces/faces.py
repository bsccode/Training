def convert():
    HappySad = input("Are you happy :) or sad :( ? \n")
    HappySad = HappySad.replace(":)","🙂")
    HappySad = HappySad.replace(":(","🙁")
    return print(HappySad)
convert()