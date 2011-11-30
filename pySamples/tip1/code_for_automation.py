#!/usr/bin/env python

animal_info_dict = {
        "dog":   {"leg": "four"},
        "chick": {"leg": "two"},
        "cat":   {"leg": "four"}
        }

def get_animal_info1(animal):
    try:
        info = animal_info_dict[animal]
        legs = info['leg']
        msg = "The %s has %s legs." % (animal, legs)
    except:
        msg = "There is unknown animal."     
    return msg

def main():
    animals = ["dog", "chick", "cat"]
    for name in animals:
        msg = get_animal_info1(name)
        print(msg)

if __name__== "__main__":
    main()

