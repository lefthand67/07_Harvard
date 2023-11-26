def main():
    
    height = get_int("Height: ")
    
    while height < 1 or height > 8:
        print("Choose a number between 1 and 8")
        height = get_int("Height: ")

    for i in range(height):
        
        empty_line = ''
        bricks = ''

        counter = 0
        while counter < height - i - 1:
            empty_line += ' '
            counter += 1

        for j in range(i+1):
            bricks += '#'

        print(empty_line + bricks + '  ' + bricks)


def get_int(prompt):
    while True:
        try:
            return int(input(prompt))
        except ValueError:
            print("Not an integer")
            

main()
