// Candidates have name and vote count
public class Candidate {

    public String name;
    public int votes;

    public Candidate(String name, int votes) {
        this.name = name;
        this.votes = votes;
    }

    public String displayName() {
        return name;
    }

    public int displayVotes() {
        return votes;
    }

    // public static void main(String[] args) {

    // }

}