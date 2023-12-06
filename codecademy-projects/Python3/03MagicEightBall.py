# Write a magic8.py Python program that can answer any “Yes” or “No” question with a different fortune each time it executes.


import random

random_number = random.randint(1,9)
name = "Poopy Brain head"
question =  "Am I a bad person?"
answer = ""

print (random_number)

if random_number == 1:
  answer = "yes - definitely"
elif random_number == 2:
  answer = "It is decidedly so"
elif random_number == 3:
  answer = "poopoing"
elif random_number == 4:
  answer = "still pooping"
elif random_number == 5:
  answer = "popping more"
elif random_number == 6:
  answer = "maune"
elif random_number == 7:
  answer =" esperanto"
elif random_number == 8:
  answer = "pooping in esperanto"
elif random_number == 9:
  answer = "morestftr"
else:
   answer = "Error"

print(name + " asks: " + question)
print("magic 8 balls answer is " + answer)