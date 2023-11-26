import csv
import sys

def main():

    # TODO: Check for command-line usage
    if len(sys.argv) != 3:
        print("Usage: python3 database.csv sequence.txt")
        sys.exit(1)

    # TODO: Read database file into a variable
    database = []
    with open(sys.argv[1], 'r') as file:
        reader = csv.reader(file)
        for pair in reader:
            database.append(pair)
    print(database)

#    for tandem in database[0][1:]:
#        print(tandem)

#    for data in database[1:][1:]:
#        print(data)

    # TODO: Find longest match of each STR in DNA sequence

    # TODO: Check database for matching profiles


main()
