# Summary:
# This script simulates a Pokémon battle game using object-oriented programming concepts in Python.
# It features two main classes - Trainer and Pokemon - to represent trainers and their Pokémon respectively.
# The game allows users to pick trainers, randomize Pokémon, and simulate battles between trainers.


import random

#     Represents a Pokémon with a name, attack power, and health. 

class Pokemon:
#        Initializes a new Pokémon instance. 
    def __init__(self, name, attack, health):
        self.name = name        # Name of the Pokémon
        self.attack = attack    # Attack power of the Pokémon
        self.health = health    # Health value of the Pokémon

#       Returns a string representation of the Pokémon. 

    def __repr__(self):
        return self.name

#    Represents a Pokémon trainer with a name and a collection of Pokémon. 

class Trainer:

#    Initializes a new Trainer instance. 

    def __init__(self, name):
        self.name = name        # Name of the Trainer
        self.pokemon = []       # List to hold Trainer's Pokémon

#        Adds unique random Pokémon to the trainer's collection. 

    def add_random_pokemon(self, pokemon_pool, num_of_pokemon=3):
        unique_pokemon = set(pokemon_pool) - set(self.pokemon)
        while len(self.pokemon) < num_of_pokemon:
            random_pokemon = random.choice(list(unique_pokemon))
            self.pokemon.append(random_pokemon)
            unique_pokemon.remove(random_pokemon)

#   Clears the trainer's current Pokémon. 

    def clear_pokemon(self):
        self.pokemon = []

# Returns a string representation of the Trainer.

    def __repr__(self):
        return self.name

# Creating instances of trainers

trainer1 = Trainer("arry")
trainer2 = Trainer("barry")
trainer3 = Trainer("carry")
trainer4 = Trainer("darry")
trainers = [trainer1,trainer2,trainer3,trainer4]

# Creating a pool of Pokémon

pokemon_pool = [
    Pokemon("pikachu", 50, 150),
    Pokemon("squirtle", 70, 130),
    Pokemon("bulbasaur", 70, 180),
    Pokemon("charmander", 30, 210),
    Pokemon("butterfree", 100, 40),
    Pokemon("mewtwo", 200, 150),
    ]

# Randomizes Pokémon for each trainer.

def randomise_pokemon():
    for trainer in trainers:
        trainer.clear_pokemon()
        trainer.add_random_pokemon(pokemon_pool)  # Assign new Pokémon
    print("Pokémon have been randomized.")

#     Lists all Pokémon for each trainer. 

def list_pokemon():
    for trainer in [trainer1, trainer2, trainer3, trainer4]:
        print(f"{trainer.name}'s Pokémon:")
        for pokemon in trainer.pokemon:
            print(f"  {pokemon.name} - Attack: {pokemon.attack}, Health: {pokemon.health}")

#     Handles user input for selecting trainers and options. 

def menu():    
    choice = ""
    random_choice = ""
    randomise_pokemon()
    print("Welcome to the pokemon battle extravaganza !!!")
    print("Please pick your combatant: arry, barry, carry, darry")
    print("if you want to randomise the trainers pokemon write randomise")
    print("if you want to see the pokemon (Cheater) then write list")
    
    user_choice = input("Enter your choice: ").lower()

    match user_choice:
        case "arry":
            choice = trainer1
        case "barry":
            choice = trainer2
        case "carry":
            choice = trainer3
        case "darry":
            choice = trainer4
        case "list":
            list_pokemon()
        case "randomise":
            randomise_pokemon()
        case _:
            print("Invalid choice.")
            return None, None
    
    if choice:
        remaining_trainers = [t for t in trainers if t != choice]
        random_choice = random.choice(remaining_trainers)
    
    return choice, random_choice
    
#     Simulates a battle between two trainers. 

def battle_logic(choice, random_choice):
    while True:
        # Check if all Pokémon of either trainer are defeated
        if all(pokemon.health <= 0 for pokemon in choice.pokemon):
            return f"{random_choice.name} wins!"
        elif all(pokemon.health <= 0 for pokemon in random_choice.pokemon):
            return f"{choice.name} wins!"

        # Randomly select who attacks this round
        attacking_trainer, defending_trainer = random.sample([choice, random_choice], 2)

        # Select the first Pokémon with health above 0 for each trainer
        attack_pokemon = next((p for p in attacking_trainer.pokemon if p.health > 0), None)
        defend_pokemon = next((p for p in defending_trainer.pokemon if p.health > 0), None)

        if attack_pokemon is None or defend_pokemon is None:
            # In case there's no valid Pokémon to fight
            return "No valid Pokémon to fight."

        # Perform the attack
        print(f"{attacking_trainer.name}'s {attack_pokemon.name} attacks {defending_trainer.name}'s {defend_pokemon.name} with {attack_pokemon.attack} damage")
        defend_pokemon.health -= attack_pokemon.attack

        # Check if the defending Pokémon is defeated
        if defend_pokemon.health <= 0:
            print(f"{defend_pokemon.name} is defeated!")

#     Main function to run the game loop. 
        
def main():
    while True:
        choice, random_choice = menu()
        if choice and random_choice:
            result = battle_logic(choice, random_choice)
            print(result)
            again = input("Play again? \n y/n: ")
            if again == "y":
                continue
            else:
                break


if __name__ == "__main__":
    main()
