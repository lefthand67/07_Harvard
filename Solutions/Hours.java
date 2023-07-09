import java.util.Scanner;

public class Hours {
    public static void main(String[] args) {

        // getting number of weeks
        System.out.print("Number of weeks taking CS50: ");
        Scanner input = new Scanner(System.in);
        int numWeeks = input.nextInt();
        
        // declaring a list of hours per week
        int[] hours;
        hours = new int[numWeeks];
        
        // getting the list of hours
        int count = 0;
        do {
            System.out.printf("Week %d HW Hours: ", count);
            int number = input.nextInt(); 
            hours[count] = number;
            count++;
        } while (count < numWeeks);
        
        // getting the desired action
        System.out.print("Enter T for total hours, A for average hours per week: ");
        char action = input.next(".").charAt(0);
        if (action == 't' || action == 'a') {
            int casesDistance = 'a' - 'A';
            int new_index = action - casesDistance;
            action = (char) new_index;
        }

        // printing the result
        System.out.printf("%.1f hours", calcHours(numWeeks, hours, action));
    }

    public static float calcHours(int numberOfWeeks, int[] args, char action) {
        float total = 0;
        float result = 0;

        // counting sum
        for (int i : args) {
            float num = (float) i;
            total += num;
        }
        // checking input for action
        if (action == 'T') {
            result = total;
        } else if (action == 'A') {
            // counting average
            result = total / numberOfWeeks;
        } else {
            System.out.println("Wrong decision.");
        }
        return result;
    }
}