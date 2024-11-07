#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Function to solve the 0/1 Knapsack problem using dynamic programming
int knapSack(int W, vector<int> &weights, vector<int> &values, int items)
{
    // Create a table to store maximum profit values for subproblems
    vector<vector<int>> table(items + 1, vector<int>(W + 1, 0));

    // Build the table in a bottom-up manner
    for (int i = 0; i <= items; i++)
    {
        for (int w = 0; w <= W; w++)
        {
            if (i == 0 || w == 0)
            {
                table[i][w] = 0; // Base case: no items or no capacity
            }
            else if (weights[i - 1] <= w)
            {
                // If the current item's weight is less than or equal to the current capacity
                table[i][w] = max(values[i - 1] + table[i - 1][w - weights[i - 1]], table[i - 1][w]);
            }
            else
            {
                // If the current item's weight is greater than the current capacity
                table[i][w] = table[i - 1][w];
            }
        }
    }

    // The bottom-right cell contains the maximum profit
    return table[items][W];
}

int main()
{
    int n, W;

    // Input values and weights
    cout << "Enter number of items: ";
    cin >> n;

    vector<int> values(n), weights(n);

    cout << "Enter values of items (space-separated): ";
    for (int i = 0; i < n; i++)
    {
        cin >> values[i];
    }

    cout << "Enter weights of items (space-separated): ";
    for (int i = 0; i < n; i++)
    {
        cin >> weights[i];
    }

    cout << "Enter Knapsack Capacity: ";
    cin >> W;

    // Call knapSack function to get the maximum profit
    int maxProfit = knapSack(W, weights, values, n);

    // Output the result
    cout << "Maximum profit that can be achieved: " << maxProfit << endl;

    return 0;
}
