import names
from random import randint
from sys import argv

if len(sys.argv) != 2:
    print("Usage: getNames.py <number of names>")
    exit()

with open("./names.txt", "w") as f:
    for i in range(int(argv[1])):
        print(names.get_full_name(), file=f)