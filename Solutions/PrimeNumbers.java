import java.util.Scanner;

public class PrimeNumbers {

    public static void main(String[] args) {

        Scanner scanner = new Scanner(System.in);
        System.out.println("Enter a range: ");
        int rng = scanner.nextInt();

        for (int i = 4; i < rng+1; i++) {
            
            boolean prime = true;
            
            if (!(i%2 == 0)) {
                
                for (int j = 3; j < i; j++) {
                    if (i % j == 0) {
                        prime = false;
                        break;
                    } 
                }

                if (prime) {
                System.out.print(i+" ");
                }
            }
        }
    }
}