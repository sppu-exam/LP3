#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Recursive function to solve the 0/1 Knapsack problem
int knapSack(int W, vector<int> &weights, vector<int> &values, int items)
{
    if (items == 0 || W == 0)
    {
        return 0;
    }

    int includeItem = 0;
    if (weights[items - 1] <= W)
    {
        includeItem = values[items - 1] + knapSack(W - weights[items - 1], weights, values, items - 1);
    }
    int excludeItem = knapSack(W, weights, values, items - 1);
    return max(includeItem, excludeItem);
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
