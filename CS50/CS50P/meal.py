def main():

    answer = input("what is the time?\n").strip()
    time = convert(answer)
    if time >= 7 and time <=8:
        print("breakfast time")
    elif time >=12 and time <= 13:
        print("lunch time")
    elif time >=18 and time <= 19:
        print("dinner time")

def convert(time):
    hour,minute = time.split(":")
    hour = float(hour)
    minute = float(minute)
    minute = (minute/60)
    ANS = hour + minute
    return ANS


if __name__ == "__main__":
    main()