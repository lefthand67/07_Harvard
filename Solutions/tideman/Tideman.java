import java.util.Scanner;

public class Tideman {
    
    // Max number of candidates
    private static final int MAX = 9;

    // preferences[i][j] is number of voters who prefer i over j
    private static int[][] preferences = new int[MAX][MAX];

    // locked[i][j] means i is locked in over j
    private static boolean locked[][] = new boolean[MAX][MAX];

    // Array of candidates
    private static String[] candidates = new String[MAX];
    private static Pair[] pairs = new Pair[MAX*(MAX - 1)/2];

    private static int pairCount;
    private static int candidateCount;

    public static void main(String[] args) {

        candidateCount = args.length;

        // Check for invalid usage
        if (candidateCount < 2) {
            System.out.printf("Usage: java tideman candidate1 candidate2 ...\n");
            System.exit(1);
        }

        // Populate array of candidates
        if (candidateCount > MAX) {
            System.out.printf("Maximum number of candidates is %d\n", MAX);
            System.exit(2);
        }
        for (int i = 0; i < candidateCount; i++) {
            candidates[i] = args[i];
        }

        // clear preferences matrix
        for (int i = 0; i < candidateCount; i++) {
            for (int j = 0; j < candidateCount; j++) {
                preferences[i][j] = 0;
            }
        }

        // Clear graph of locked in pairs
        for (int i = 0; i < candidateCount; i++) {
            for (int j = 0; j < candidateCount; j++) {
                locked[i][j] = false;
            }
        }

        Scanner input = new Scanner(System.in);
        System.out.print("Number of voters: ");
        int voterCount = input.nextInt();

        // Query for votes
        for (int i = 0; i < voterCount; i++) {

            System.out.printf("Voter %d:\n", i+1);

            // ranks[i] is voter's ith preference
            int[] ranks = new int[candidateCount];

            // Query for each rank
            for (int j = 0; j < candidateCount; j++) {
                System.out.printf("Rank %d: ", j + 1);
                String name = input.next();

                if (!vote(j, name, ranks)) {
                    System.out.println("Invalid vote.");
                    System.exit(3);
                }  
            }
            recordPreferences(ranks);
            System.out.println();
        }
        input.close();

        // showPreferencesMatrix();
        addPairs();
        sortPairs();
        lockPairs();
        // showLockedMatrix();
        printWinner();
    }

    // Update ranks given a new vote
    public static boolean vote(int rank, String name, int[] ranks) {
        for (int i = 0; i < candidateCount; i++) {
            if (candidates[i].compareToIgnoreCase(name) == 0) {
                ranks[rank] = i;
                return true;
            }
        }    
        return false;
    }

    // Update preferences given one voter's ranks
    public static void recordPreferences(int[] ranks) {
        for (int i = 0; i < candidateCount - 1; i++) {
            int winner = ranks[i];
            int loser = ranks[i+1];
            preferences[winner][loser] += 1;

            // pairs creating and preferences updating
            // pairs[i] = new Pair(winner, loser);
            // preferences[pairs[i].winner][pairs[i].loser] += 1;
        }
    }

    public static void showPreferencesMatrix() {
        System.out.println("Preferences matrix:");
        // weighted adjacency matrix of preferences
        for (int i = 0; i < candidateCount; i++) {
            for (int j = 0; j < candidateCount; j++) {
                System.out.print(preferences[i][j]);
            }
            System.out.println();
        }
        System.out.println();
    }

    // Record pairs of candidates where one is preferred over the other
    public static void addPairs() {
        pairCount = 0;
        for (int i = 0; i < candidateCount; i++) {
            for (int j = 0; j < candidateCount; j++) {
                if (preferences[i][j] > 0) {
                    pairs[pairCount] = new Pair(i, j);
                    pairCount++;
                }
            }
        }
    }

    // Sort pairs in decreasing order by strength of victory
    public static void sortPairs() {
        for (int i = 0; i < pairCount-1; i++) {
            for (int j = 0; j < pairCount-1; j++) {
                if (preferences[pairs[j].winner][pairs[j].loser] < 
                    preferences[pairs[j+1].winner][pairs[j+1].loser]) {
                        Pair temp = pairs[j];
                        pairs[j] = pairs[j+1];
                        pairs[j+1] = temp;
                }
            }
        }

    }

    // Lock pairs into the candidate graph in order, without creating cycles
    public static void lockPairs() {
        // lock first pair by default
        locked[pairs[0].winner][pairs[0].loser] = true;
        // check all (except for first one) pairs for cycles
        for (int i = 1; i < pairCount; i++) {
            if (!checkCycle(i)) {
                locked[pairs[i].winner][pairs[i].loser] = true;
            }
        }
    }

    //  check a pair for cycle
    public static boolean checkCycle(int n) {
        for (int i = 1; i < n+1; i++) {
            if (pairs[n].loser == pairs[n-i].winner) {
                return true;
            }
        }
        return false;
    }
     
    public static void showLockedMatrix() {
        System.out.println("Locked matrix:");
        // locked graph
        for (int i = 0; i < candidateCount; i++) {
            for (int j = 0; j < candidateCount; j++) {
                System.out.print(locked[i][j] + " ");
            }
            System.out.println();
        }
        System.out.println();
    }

    // Print the winner of the election
    public static void printWinner() {
        for (int i = 0; i < candidateCount*candidateCount; i++) {
            for (int j = 0; j < candidateCount*candidateCount; j++) {
                if (locked[j][i]) {
                    System.out.println(candidates[j]);
                    System.exit(0);
                }
            }
        }
    }
}
