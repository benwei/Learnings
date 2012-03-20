#!/usr/bin/env python

# origin one
def show_animal_info0(animal):
    if animal == 'dog':
        print("The dog has four legs.")
    elif animal == 'chick':
        print("The chick has two legs.")
    else:
        print("There is an unknown animal")

# refactoring stage 1
animal_info_dict = {
        "dog":   "four legs",
        "chick": "two legs"
        }

def show_animal_info1(animal):
    try:
        info = animal_info_dict[animal]
        print("The %s has %s." % (animal, info))
    except:
        print("There is unknown animal.")     

def main():
    show_animal_info1("dog")
    show_animal_info1("chick")
    show_animal_info1("cat")

if __name__== "__main__":
    main()

