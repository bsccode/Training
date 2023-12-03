def square_sum(numbers):
    array = []
    sum = 0
    for i in numbers:
        array.append(i**2)
        for j in array:
            sum += j
            
            print(sum) 
    return sum

print(square_sum([2,6]))

