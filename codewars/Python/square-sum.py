def square_sum(numbers):
    if isinstance(numbers, int):
        numbers = [numbers]
    num = 0
    for number in numbers:
        numbsqua = number ** 2
        num += numbsqua
    return num

print(square_sum([8, 9]))  # Output: 145
print(square_sum(7))       # Output: 49
