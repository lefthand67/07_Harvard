import java.util.Scanner;

public class Plurality {

    // Max number of candidates
    static final int MAX = 9;

    // Array of candidates
    private static Candidate[] candidates = new Candidate[MAX];

    // Number of candidates
    private static int candidateCount;

    public static void main(String[] args) {
        
        candidateCount = args.length;

        // Check for invalid usage
        if (candidateCount < 1) {
            System.out.println("Usage: java plurality candidate1 candidate2 ...");
            System.exit(1);
        }
        
        // Populate array of candidates
        if (candidateCount > MAX) {
            System.out.printf("Maximum number of candidates is %d\n" + MAX);
            System.exit(2);
        }
        for (int i = 0; i < candidateCount; i++) {
            candidates[i] = new Candidate(args[i], 0);
        }
        try (Scanner input = new Scanner(System.in)) {
            System.out.print("Number of voters: ");
            int voterCount = input.nextInt();
                
            // Loop over all voters
            for (int i = 0; i < voterCount; i++) {
                System.out.print("Vote: ");
                String name = input.next();  // takes one string before space

                // Check for invalid vote
                if (!vote(name)) {
                    System.out.println("Invalid vote.\n");
                }
            }
        }

        // Display winner of election
        printWinner();
    }

    // Update vote totals given a new vote
    public static boolean vote (String name) {
        for (int i = 0; i < candidateCount; i++) {
            int result = name.compareToIgnoreCase(candidates[i].displayName());
            if (result == 0) {
                candidates[i].votes++;
                return true;
            }
        }
        return false;
    }

    // Print the winner (or winners) of the election
    public static void printWinner() {
        int biggestVote = 0;
        for (int i = 0; i < candidateCount; i++) {
            if (biggestVote < candidates[i].votes) {
                biggestVote = candidates[i].votes;
            }
        }
        for (int i = 0; i < candidateCount; i++) {
            if (candidates[i].votes == biggestVote) {
                System.out.println(candidates[i].name);
            }
        }
    }
}