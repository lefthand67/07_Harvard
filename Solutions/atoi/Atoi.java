import java.util.Scanner;

public class Atoi{

    private static String number;

    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        System.out.print("Enter a positive integer: ");
        number = input.next();
        input.close();

        int zeroIndex = '0';
        int nineIndex = '9';

        for (int i = 0; i < number.length(); i++) {
            int charToIndex = number.charAt(i);
            if ((charToIndex < zeroIndex) ||
                (charToIndex > nineIndex)) {
                System.out.println("Invalid Input!");
                System.exit(1);
            }
        }
        // Convert string to int
        System.out.printf("%d\n", convert(number));
    }

    public static int convert(String number) {

        // base case - lowest decimal reached
        if (number.length() == 1) {
            // System.out.println("Smallest decimal is: " + (number.charAt(0) - '0'));
            return number.charAt(0) - '0';
        }

        // recursive case

        // we'll cut the string from beginning
        int firstChar = 0;
        
        // getting biggest number each cycle
        int intNumber = number.charAt(firstChar) - '0';
        for (int i = 1; i < number.length(); i++) {
            intNumber *= 10;
        }
        // System.out.println("intNumber check: " + intNumber);

        // iterating through the chars from beginning to end
        return intNumber + convert(number.substring(++firstChar, number.length()));
    }
}