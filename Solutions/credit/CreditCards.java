import java.util.Scanner;

public class CreditCards {
    public static void main(String[] args) {

        // String number = "4003600000000014";
        String number;
        try(Scanner inp = new Scanner(System.in)) {
            System.out.print("Number: ");
            number = inp.nextLine();
        }

        int sum = 0;
        for(int i = number.length() - 2; i > -1; i -= 2) {
            // adding every second-to-last digit
            // get ASCII value and convert to int 
            int digit = number.charAt(i) - '0';
            digit *= 2;
            if(digit > 10) {
                // convert digit to string
                String chars = digit + "";
                for(int j = 0; j < chars.length(); j++) {
                    // and add every char to sum
                    sum += (chars.charAt(j) - '0');
                }
            }
            else {
                sum += digit;
            }
            // adding the rest of digits to sum
            digit = number.charAt(i+1) - '0';
            sum += digit;
        }

        if(sum%10 == 0) {
            System.out.println("VISA");
        }
        else {
            System.out.println("INVALID");
        }

    }
}
