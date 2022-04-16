import random
import sys

#GENERATE RANDOM PEOPLE GIVEN BY argv[1] BASED ON NAMES FROM names.txt AND GIVE THEM UNIQUE SEVEN DIGITS INCIDES

if len(sys.argv) != 2:
    print("Usage: generatePeople.py <number of people>")
    exit()

people = []
with open("./names.txt") as f:
    for line in f:
        people.append(line.strip().split())

with open("./people.txt", "w") as f:
    for i in range(int(sys.argv[1])):
        person = random.choice(people)
        while(len(person[0]) > 12 or len(person[1]) > 12):
            person = random.choice(people)
        print(1000000+i, *person, file=f)
