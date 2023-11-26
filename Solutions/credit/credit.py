def main():

    number = get_int("Enter a card number: ")

    # let's add 0 digit to the beginning of the list if it's modulo 2 is not 0
    # it will allow us to go by two digits in each iteration
    changed = False
    if len(number) % 2 != 0:
        number = [0] + number
        changed = True

    # let's create a list for all the numbers
    lst = list()

    for i in range(len(number)-1, 0, -2):
        
        lst.append(int(number[i]))

        every_other_digit = int(number[i-1])*2
        if every_other_digit > 9:
            for j in str(every_other_digit):
                lst.append(int(j))
        else:
            lst.append(every_other_digit)

    length = (len(number) - 1) if changed else len(number)
        
    print(length)
    if sum(lst) % 10 == 0:
        if length == 15:
            print('AMEX\n')
        elif (length == 13 or len(number) == 16) and int(number[0]) == 4:
            print('VISA\n')
        else:
            print('MASTERCARD\n')
    else:
        print('Invalid'.upper())


def get_int(prompt):
    while True:
        try:
            return [int(i) for i in input(prompt)]
        except:
            print("Not an Integer")


main()
