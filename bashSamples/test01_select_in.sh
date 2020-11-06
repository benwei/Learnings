#!/bin/sh
# Written By Ben Wei 2014
echo "--- Welcome to shell MUD ---"

PS3='center> '
map=("There is a road in from of you" "your home door" "A garden" "the door of garage is opened") 
mapprefix=("East" "West" "North" "South")
options=()
for ((i=0; i<${#map[@]}; ++i)) ; do
    options[$i]="${mapprefix[$i]} - ${map[$i]}"
done
options[$i]="Quit"

select opt in "${options[@]}"
do
    case $opt in
        "East"*)
            echo "${map[0]}"
            PS3='Road> '
            ;;
        "West"*)
            echo "${map[1]}"
            PS3='Home> '
            ;;
        "North"*)
            echo "${map[2]}"
            PS3='Garden> '
            ;;
        "South"*)
            echo "${map[3]}"
            PS3='Garage> '
            ;;
        "Quit")
            echo "Bye! Bye!"
            break
            ;;
        *) echo "enter wrong direction";;
    esac
done

