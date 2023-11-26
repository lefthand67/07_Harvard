from sys import argv, exit
from pyfiglet import Figlet
from random import randrange


def main():

    s = input("Input: ")

    figlet = Figlet()
    lst = figlet.getFonts()

    if len(argv) == 1:
        random_num = randrange(0, len(lst))
        font =lst[random_num] 
    
    elif len(argv) == 3:

        if argv[1] == '-f' or argv[1] == '--font':
            font=argv[2]
        
        else:
            exit("Invalid usage")

    else:
        exit("Invalid usage")

    figlet.setFont(font=font)
   
    print(f"Output: {font}")
    print(figlet.renderText(s))


main()
