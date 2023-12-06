#must start with 2 letters
#min of 2 and max of 6
#first number can not be 0
#numbers must come at end
# no period space or punctuation

def main():
    plate = input("Plate: ")
    if is_valid(plate):
        print("Valid")
    else:
        print("Invalid")


def is_valid(s):
    # Check if the length is between 2 and 6
    if len(s) < 2 or len(s) > 6:
        return False

    # Ensure the plate starts with 2 letters
    if not s[0:2].isalpha():
        return False

    # Check for presence of forbidden characters
    for char in s:
        if not char.isalpha() and not char.isdigit():
            return False

    # Checking if numbers come at the end and if the first number is not 0
    num_started = False
    for char in s[2:]:
        if char.isdigit():
            if not num_started:  # If it's the first digit
                if char == '0':
                    return False
                num_started = True
        else:
            if num_started:  # If we found a non-digit after a digit
                return False

    return True







main()