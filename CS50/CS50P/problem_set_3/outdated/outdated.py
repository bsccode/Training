

#take input of date in MM/DD/YYYY either 9/8/1636 or September 8, 1936
#convert and output same date in YYYY-MM-DD

def date():
    while True:
            string = input("Date: ").lower().replace(',', '').replace(' ', '/')
            m,d,y =  string.split('/')
            try:
                d,y = int(d), int(y)
                if d < 1 or d > 31:
                    raise ValueError
            except ValueError:
                continue
            if m == type(str):
                match m:
                    case "january":
                        m = 1
                    case "february":
                        m = 2
                    case "march":
                        m = 3
                    case "april":
                        m = 4
                    case "may":
                        m = 5
                    case "june":
                        m = 6
                    case "july":
                        m = 7
                    case "august":
                        m = 8
                    case "september":
                        m = 9
                    case "october":
                        m = 10
                    case "november":
                        m = 11
                    case "december":
                        m = 12
                    case _:
                        continue
            if m > 12 or m < 1:
                raise ValueError
            m = int(m)
            print(f"{y}-{m:02}-{d:02}")
date()


