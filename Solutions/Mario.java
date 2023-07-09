import java.util.Scanner;

public class Mario {

    public static void main(String[] args) {

        Scanner scanner = new Scanner(System.in);
        System.out.println("Enter number between 1 and 8: ");
        int n = scanner.nextInt();

        for (int i = 1; i < n+1; i++) {

            String line = "";
            int j = n + 1 - i;
            while (j > 0) {
                line +=  ' ';
                j--;
            }

            int k = i;
            while (k > 0) {
                line += '*';
                k--;
            }

            line += ' ';

            String final_line = line;
            for (int l = line.length()-1; l >= 0; l--) {
                final_line += line.charAt(l);
            }

            System.out.println(final_line);

        }



//        for (int i=1; i < n+1; i++) {
//
//            int j = n + 1 - i;
//            while (j > 0) {
//                System.out.print(" ");
//                j--;
//            }
//
//            int k = i;
//            while (k > 0) {
//                System.out.print("*");
//                k--;
//            }
//
//            System.out.print("  ");
//
//            k = i;
//            while (k > 0) {
//                System.out.print("*");
//                k--;
//            }
//
//            j = n + 1 - i;
//            while (j > 0) {
//                System.out.print(" ");
//                j--;
//            }
//
//            System.out.println();
//
//        }

    }

}