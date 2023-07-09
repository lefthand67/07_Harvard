import java.util.Scanner;

class Substitution {
    public static void main(String[] args) {
        
        String key;
        String plaintext;
        int idx;
        int newIndex;
        int asciiIndex;
        // distance between lower and upper cases
        int casesDistance = 'a' - 'A';
        char symbol;

        try(Scanner input = new Scanner(System.in)) {
            
            // input key
            do {
                key = input.nextLine();
                String message = "plaintext:  ";

                int[] upperArray;
                upperArray = new int[26];
                int[] lowerArray;
                lowerArray = new int[26];
                int idxUpper;
                int idxLower;

                // no line for key given
                if (key.length() != 26) {
                message = "Usage: java Substitution key";
                }

                for (int i = 0; i < key.length(); i++) {
                    idx = key.charAt(i);
                    
                    // incorrect key
                    if (key.length() != 26) {
                        if (idx < 'A' || (idx > 'Z' && idx < 'a') || idx > 'z') {
                            message = "Usage: java Substitution key";
                            break;
                        }
                        message = "Key must contain 26 characters.";
                    }
                    
                    // correct key check for uniqueness
                    else {
                        boolean isin = false;
                        for (int j : upperArray) {
                            if (j == idx) {
                                isin = true;
                            }
                        }
                        for (int j : lowerArray) {
                            if (j == idx) {
                                isin = true;
                            }
                        }

                        if (isin) {
                            message = "Characters must be unique";
                            break;
                        } else if (idx >= 'A' && idx <= 'Z') {
                            idxUpper = idx;
                            idxLower = idx + casesDistance;
                        } else {
                            idxUpper = idx - casesDistance;
                            idxLower = idx;
                        }
                        upperArray[i] = idxUpper;
                        lowerArray[i] = idxLower;
                    }
                }
                System.out.print(message);
            } while (key.length() != 26);

            // input plaintext
            plaintext = input.nextLine();
        }

        // key = "VCHPrZGjNTLSKFBDQWAXEUYMOI";
        // plaintext = "Hello, World";

        // get ciphertext
        System.out.print("ciphertext: ");        
        for (int i = 0; i < plaintext.length(); i++) {
            
            // get text's index for comparison
            idx = plaintext.charAt(i);

            // get an uppercase symbol 
            if (idx >= 'A' && idx <= 'Z') {
                // find index for key
                newIndex = plaintext.charAt(i) - 'A';
                symbol = key.charAt(newIndex);
                asciiIndex = key.charAt(newIndex);
                // check for key symbol's case
                if (asciiIndex < 'A' || asciiIndex > 'Z') {
                    // get its uppercase ASCII index
                    asciiIndex = symbol - casesDistance;
                    // get a symbol
                    symbol = (char) asciiIndex;
                } 
            }

            // get a lowercase symbol 
            else if (idx >= 'a' && idx <= 'z') {
                // find index for key
                newIndex = plaintext.charAt(i) - 'a';
                symbol = key.charAt(newIndex);
                asciiIndex = key.charAt(newIndex);
                // check for key symbol's case
                if (asciiIndex < 'a' || asciiIndex > 'z') {
                    // get its lowercase ASCII index
                    asciiIndex = symbol + casesDistance;
                    // get a symbol
                    symbol = (char) asciiIndex;
                } 
            }

            // get other symbols untouched
            else {
                symbol = plaintext.charAt(i);
            }
        
            System.out.print(symbol);
        }
    }
}