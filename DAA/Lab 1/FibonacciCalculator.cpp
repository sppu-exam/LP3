#include <iostream>
using namespace std;

// Recursive function to calculate Fibonacci number and count steps
int fibonacciRecursive(int n, int &stepCount)
{
    stepCount++; // Increment step count each time the function is called
    if (n <= 1)
        return n;
    return fibonacciRecursive(n - 1, stepCount) + fibonacciRecursive(n - 2, stepCount);
}

// Iterative function to calculate Fibonacci number and count steps
int fibonacciIterative(int n, int &stepCount)
{
    if (n <= 1)
    {
        stepCount = 1;
        return n;
    }

    int a1 = 0, a2 = 1, result = 0;
    stepCount = 1; // Initial setup count
    for (int i = 2; i <= n; i++)
    {
        result = a1 + a2;
        a1 = a2;
        a2 = result;
        stepCount++; // Count each iteration step
    }
    return result;
}

int main()
{
    int n;
    cout << "Enter the Fibonacci number index to calculate: ";
    cin >> n;

    int stepsRecursion = 0;
    int resultRecursive = fibonacciRecursive(n, stepsRecursion);
    cout << "Fibonacci Recursive Result: " << resultRecursive << endl;
    cout << "Fibonacci Recursive Steps: " << stepsRecursion << endl;

    int stepsIteration = 0;
    int resultIterative = fibonacciIterative(n, stepsIteration);
    cout << "Fibonacci Iterative Result: " << resultIterative << endl;
    cout << "Fibonacci Iterative Steps: " << stepsIteration << endl;

    return 0;
}