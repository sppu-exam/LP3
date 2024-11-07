import java.util.Scanner;

public class FibonacciCalculator {

    // Recursive function to calculate Fibonacci number and count steps
    public static int fibonacciRecursive(int n, int[] stepCount) {
        stepCount[0]++; // Increment step count each time the function is called
        if (n <= 1)
            return n;
        return fibonacciRecursive(n - 1, stepCount) + fibonacciRecursive(n - 2, stepCount);
    }


    // Iterative function to calculate Fibonacci number and count steps
    public static int fibonacciIterative(int n, int[] stepCount) {
        if (n <= 1) {
            stepCount[0] = 1;
            return n;
        }

        int a1 = 0, a2 = 1, result = 0;
        stepCount[0] = 1; // Initial setup count
        for (int i = 2; i <= n; i++) {
            result = a1 + a2;
            a1 = a2;
            a2 = result;
            stepCount[0]++; // Count each iteration step
        }
        return result;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter the Fibonacci number index to calculate: ");
        int n = scanner.nextInt();

        int[] stepsRecursion = { 0 };
        int resultRecursive = fibonacciRecursive(n, stepsRecursion);
        System.out.println("Fibonacci Recursive Result: " + resultRecursive);
        System.out.println("Fibonacci Recursive Steps: " + stepsRecursion[0]);

        int[] stepsIteration = { 0 };
        int resultIterative = fibonacciIterative(n, stepsIteration);
        System.out.println("Fibonacci Iterative Result: " + resultIterative);
        System.out.println("Fibonacci Iterative Steps: " + stepsIteration[0]);

        scanner.close();
    }
}
