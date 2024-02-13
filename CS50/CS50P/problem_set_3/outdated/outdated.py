

#take input of date in MM/DD/YYYY either 9/8/1636 or September 8, 1936
#convert and output same date in YYYY-MM-DD

def date():
    while True:
        string = input("Date: ").lower().replace(',', '').strip()

        # Split the input differently based on presence of slashes
        if '/' in string:
            parts = string.split('/')
            if len(parts) != 3:
                print("Invalid date. Please try again.")
                continue
            month, day, year = int(parts[0]), int(parts[1]), int(parts[2])
        else:
            parts = string.split()
            if len(parts) != 3:
                print("Invalid date. Please try again.")
                continue
            day, month, year = int(parts[0]), parts[1], int(parts[2])

            # Convert month to number if it's a word
            if month.isalpha():
                months = ["january", "february", "march", "april", "may", "june",
                          "july", "august", "september", "october", "november", "december"]
                if month in months:
                    month = months.index(month) + 1
                else:
                    print("Invalid month name. Please try again.")
                    continue

        # Check if day and month are valid
        try:
            if day < 1 or day > 31 or month < 1 or month > 12:
                raise ValueError

            # Print the date in YYYY-MM-DD format
            print(f"{year}-{month:02d}-{day:02d}")
            break

        except ValueError:
            print("Invalid date. Please try again.")

date()

