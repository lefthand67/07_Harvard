import sys
import csv

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

    # TODO: Read DNA sequence file into a variable
    tandems = [tandem for tandem in database[0][1:]]
    results = list()
    with open(sys.argv[2], 'r') as fhand:
        for line in fhand:
            sequence = line

    # TODO: Find longest match of each STR in DNA sequence
        for tandem in tandems: 
            results.append(longest_match(sequence, tandem))

    # TODO: Check database for matching profiles
    number_of_tandems = len(tandems)
    for i in range(1, len(database)):
        counter = 0;
        for j in range(number_of_tandems):
            if int(database[i][j+1]) == results[j]:
                counter += 1

        if counter == number_of_tandems:
            print(f"{database[i][0]}")
            return 0

    print("No match")
    return 0


def longest_match(sequence, subsequence):
    """Returns length of longest run of subsequence in sequence."""

    # Initialize variables
    longest_run = 0
    subsequence_length = len(subsequence)
    sequence_length = len(sequence)

    # Check each character in sequence for most consecutive runs of subsequence
    for i in range(sequence_length):

        # Initialize count of consecutive runs
        count = 0
        # Check for a subsequence match in a "substring" (a subset of characters) within sequence
        # If a match, move substring to next potential match in sequence
        # Continue moving substring and checking for matches until out of consecutive matches
        while True:

            # Adjust substring start and end
            start = i + count * subsequence_length
            end = start + subsequence_length

            # If there is a match in the substring
            if sequence[start:end] == subsequence:
                count += 1
            
            # If there is no match in the substring
            else:
                break
        
        # Update most consecutive matches found
        longest_run = max(longest_run, count)

    # After checking for runs at each character in seqeuence, return longest run found
    return longest_run


main()
