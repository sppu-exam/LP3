import java.util.Scanner;

public class Knapsack {

    // Recursive function to solve the 0/1 Knapsack problem
    public static int knapSack(int W, int[] weights, int[] values, int items) {
        if (items == 0 || W == 0) {
            return 0;
        }

        // If the current item's weight is less than or equal to the remaining capacity
        int includeItem = 0;
        if (weights[items - 1] <= W) {
            includeItem = values[items - 1] + knapSack(W - weights[items - 1], weights, values, items - 1);
        }

        // Exclude the current item
        int excludeItem = knapSack(W, weights, values, items - 1);

        // Return the maximum of including or excluding the current item
        return Math.max(includeItem, excludeItem);
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        // Input values and weights
        System.out.print("Enter number of items: ");
        int n = sc.nextInt();

        int[] values = new int[n];
        int[] weights = new int[n];

        System.out.print("Enter values of items (space-separated): ");
        for (int i = 0; i < n; i++) {
            values[i] = sc.nextInt();
        }

        System.out.print("Enter weights of items (space-separated): ");
        for (int i = 0; i < n; i++) {
            weights[i] = sc.nextInt();
        }

        System.out.print("Enter Knapsack Capacity: ");
        int W = sc.nextInt();

        // Call knapSack function to get the maximum profit
        int maxProfit = knapSack(W, weights, values, n);

        // Output the result
        System.out.println("Maximum profit that can be achieved: " + maxProfit);

        sc.close();
    }
}
