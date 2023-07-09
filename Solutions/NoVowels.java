public class NoVowels {
    
    public static void main(String[] args) {
        // check for correct command-line input
        // wrong input
        if (args.length != 1) {
            explain();
        // correct input
        } else {
            String word = args[0];
            System.out.printf("%s\n", replace(word));
        }
    }

    // replace function for correct input
    public static String replace(String input) {
        int length = input.length();

        // characters' array creation
        char[] newChars;
        newChars = new char[length];

        // characters' array initialization
        for (int i = 0; i < length; i++) {
            char character = input.charAt(i);
            char c = switch (character) {
                case 'a' -> '6';
                case 'e' -> '3';
                case 'i' -> '1';
                case 'o' -> '0';
                default -> character;
            };
            newChars[i] = c;
        }

        // creating a new String out of a char array
        String newWord = new String(newChars);
        return newWord;
    }

    // message function for wrong input
    public static int explain() {
        System.out.println("Usage: java NoVowels word");
        // error indication
        return 1;
    }

}