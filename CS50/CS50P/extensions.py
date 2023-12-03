def extend():
    extension = input("please tell me your file and extension. \n").lower().strip()
    if extension.endswith(".gif") == True:
        print("image/gif")
    elif extension.endswith(".jpg") == True:
        print("image/jpeg")
    elif extension.endswith(".jpeg") == True:
        print("image/jpeg")
    elif extension.endswith(".png") == True:
        print("image/png")
    elif extension.endswith(".pdf") == True:
        print("application/pdf")
    elif extension.endswith(".txt") == True:
        print("text/plain")
    elif extension.endswith(".zip") == True:
        print("application/zip")
    else:
        print("application/octet-stream")
    return

extend()