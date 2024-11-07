#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Job class to represent a job with an identifier, deadline, and profit
class Job
{
public:
    char id;
    int deadline;
    int profit;
    Job(char id, int deadline, int profit) : id(id), deadline(deadline), profit(profit) {}
};

// Comparator function to sort jobs by profit in descending order
bool compare(Job a, Job b)
{
    return a.profit > b.profit;
}

// Function to schedule jobs to maximize profit
void printJobSequence(vector<Job> &jobs)
{
    // Sort the jobs based on profit in descending order
    sort(jobs.begin(), jobs.end(), compare);

    // Find the maximum deadline to determine the number of available slots
    int maxDeadline = 0;
    for (auto &job : jobs)
    {
        maxDeadline = max(maxDeadline, job.deadline);
    }

    // Initialize slots for job sequence and track used slots
    vector<char> result(maxDeadline, '-'); // To store job ids in the sequence
    vector<bool> slot(maxDeadline, false); // To check if a slot is filled

    int totalProfit = 0;

    // Iterate over each job to schedule it
    for (auto &job : jobs)
    {
        // Try to find a slot for this job (starting from its deadline)
        for (int j = job.deadline - 1; j >= 0; j--)
        {
            if (!slot[j])
            {                              // If the slot is empty
                slot[j] = true;            // Mark this slot as occupied
                result[j] = job.id;        // Add job id to result
                totalProfit += job.profit; // Add profit
                break;
            }
        }
    }

    // Display the job sequence
    cout << "Job Sequence: ";
    for (char id : result)
    {
        if (id != '-')
        {
            cout << id << " ";
        }
    }
    cout << "\nTotal Profit: " << totalProfit << endl;
}

int main()
{
    int n;
    cout << "Enter total number of jobs: ";
    cin >> n;

    vector<Job> jobs;
    cout << "Enter job id, deadline, and profit for each job:\n";
    for (int i = 0; i < n; i++)
    {
        char id;
        int deadline, profit;
        cin >> id >> deadline >> profit;
        jobs.emplace_back(id, deadline, profit);
    }

    // Schedule jobs and print the result
    printJobSequence(jobs);

    return 0;
}
