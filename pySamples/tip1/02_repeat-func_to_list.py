#!/usr/bin/env python

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
    animals = ["dog", "chick", "cat"]
    for name in animals:
        show_animal_info1(name)

if __name__== "__main__":
    main()

