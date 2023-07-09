import java.util.Scanner;

public class Scrabble {
    public static void main(String[] args) {
        
        // Points assigned to each letter of the alphabet
        int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 
                        1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 
                        4, 8, 4, 10};
        
        String word1;
        String word2;

        try(Scanner inp = new Scanner(System.in)) {
            System.out.print("First player's word: ");
            word1 = inp.nextLine().toLowerCase();
            System.out.print("Second player's word: ");
            word2 = inp.nextLine().toLowerCase();
        }

        char a = 'a';
        int decrement_idx = (int) a;

        int score1 = 0;
        for(int i = 0; i < word1.length(); i++) {
            char letter = word1.charAt(i);
            int letter_idx = (int) letter - decrement_idx;
            if (letter_idx >= 0 && letter_idx < 26) {
                score1 += POINTS[letter_idx];
            }
        }
        // System.out.println(score1);

        int score2 = 0;
        for(int j = 0; j < word2.length(); j++) {
            char letter = word2.charAt(j);
            int letter_idx = (int) letter - decrement_idx;
            if (letter_idx >= 0 && letter_idx < 26) {
                score2 += POINTS[letter_idx];
            }
        }
        // System.out.println(score2);


        if (score1 > score2) {
            System.out.println("Player 1 wins!");
        }
        else if (score1 < score2) {
            System.out.println("Player 2 wins!");
        }
        else {
            System.out.println("Tie!");
        }
    }
}