import java.util.Scanner;

public class Atoi{

    private static String number;
    private static int zeroIndex = '0';
    private static int nineIndex = '9';

    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        System.out.print("Enter a positive integer: ");
        number = input.next();
        input.close();

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
        System.exit(0);
    }

    public static int convert(String number) {

        // start with the biggest decimal (at index 0)
        int firstChar = 0;
        int intNumber = number.charAt(firstChar) - '0';
        
        // base case - lowest decimal reached
        
        if (number.length() == 1) {
            // System.out.println("The smallest decimal is: " + (number.charAt(0) - '0'));
            return intNumber;
        }

        // recursive case

        // we cut the string from beginning
        // multiply next biggest decimal on 10^n
        for (int i = 1; i < number.length(); i++) {
            intNumber *= 10;
        }
        // System.out.println("intNumber check: " + intNumber);

        // iterating through the chars from beginning to end
        return intNumber + convert(number.substring(++firstChar, number.length()));
    }
}