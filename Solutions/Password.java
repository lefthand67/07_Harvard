import java.util.Scanner;

public class Password {
    public static void main(String[] args) {

        String password;
        boolean lowerCase = false;
        boolean upperCase = false;
        boolean number = false;
        boolean symbol = false;

        try(Scanner input = new Scanner(System.in)) {
        System.out.print("Enter your password: ");
        password = input.nextLine();
        }

        int a = 'a';
        int z = 'z';
        int A = 'A';
        int Z = 'Z';
        int zero = '0';
        int nine = '9';

        for(int i = 0; i < password.length(); i++) {
            char character = password.charAt(i);
            if(character >= a & character <= z) {
                lowerCase = true;
                // System.out.println("lowerCase: " + character);
            }
            else if(character >= A & character <= Z) {
                upperCase = true;
                // System.out.println("upperCase: " + character);
            }
            else if(character >= zero & character <= nine) {
                number = true;
                // System.out.println("number: " + character);
            }
            else {
                symbol = true;
                // System.out.println("symbol: " + character);
            }
        }

        if(lowerCase & upperCase & number & symbol) {
            System.out.println("Your password is valid!");
        }
        else {
            System.out.println("Your password needs at least one uppercase letter, lowercase letter, number and symbol!");
        }
    }
}