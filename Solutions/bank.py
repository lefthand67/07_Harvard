def main():
    
    greet = input("Greeting: ").lower()

    if greet[:5] == 'hello':
        print(0)
    
    elif greet[0] == 'h':
        print(20)
    
    else:
        print(100)

main()
