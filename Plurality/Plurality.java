public class Plurality {

    // Max number of candidates
    final int maxCandidates = 9;

    // Array of candidates
    Candidate[maxCandidates] candidates;

    // Number of candidates
    int candidateCount;

    // Function prototypes
    boolean vote(String name);
    String printWinner();

    public static void main(String[] args) {
        
        // Check for invalid usage
        if (args.length < 1) {
            System.out.println("Usage: plurality [candidate ...]");
        }

        System.out.println();
    }
}