#!/usr/bin/env python

animal_info_dict = {
        "dog":   {"leg": "four"},
        "chick": {"leg": "two"},
        "cat":   {"leg": "four"}
        }

def show_animal_info1(animal):
    try:
        info = animal_info_dict[animal]
        legs = info['leg']
        print("The %s has %s legs." % (animal, legs))
    except:
        print("There is unknown animal.")     

def main():
    animals = ["dog", "chick", "cat"]
    for name in animals:
        show_animal_info1(name)

if __name__== "__main__":
    main()

