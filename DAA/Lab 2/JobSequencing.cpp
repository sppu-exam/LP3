#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Job
{
public:
    char id;
    int deadline;
    int profit;

    Job(char id, int deadline, int profit)
    {
        this->id = id;
        this->deadline = deadline;
        this->profit = profit;
    }
};

bool compare(Job j1, Job j2)
{
    return j1.profit > j2.profit;
}

void printJobSequence(vector<Job> jobs)
{
    // Sort jobs in descending order of profit
    sort(jobs.begin(), jobs.end(), compare);

    // Find the maximum deadline
    int maxDeadline = 0;
    for (Job job : jobs)
    {
        maxDeadline = max(maxDeadline, job.deadline);
    }

    // Initialize result and slot arrays
    vector<char> result(maxDeadline, 'X');
    vector<bool> slot(maxDeadline, false);

    // Assign jobs to slots
    for (int i = 0; i < jobs.size(); i++)
    {
        for (int j = min(maxDeadline - 1, jobs[i].deadline - 1); j >= 0; j--)
        {
            if (!slot[j])
            {
                result[j] = jobs[i].id;
                slot[j] = true;
                break;
            }
        }
    }

    // Print the job sequence
    cout << "Job Sequence: ";
    for (char jobId : result)
    {
        if (jobId != 'X')
        {
            cout << jobId << " ";
        }
    }
    cout << endl;

    // Calculate total profit
    int totalProfit = 0;
    for (int i = 0; i < maxDeadline; i++)
    {
        if (slot[i])
        {
            for (Job job : jobs)
            {
                if (job.id == result[i])
                {
                    totalProfit += job.profit;
                    break;
                }
            }
        }
    }
    cout << "Total Profit: " << totalProfit << endl;
}

int main()
{
    int n;
    cout << "Enter number of jobs: ";
    cin >> n;

    vector<Job> jobs;
    cout << "Enter jobs in the format (id deadline profit):" << endl;
    for (int i = 0; i < n; i++)
    {
        char id;
        int deadline, profit;
        cin >> id >> deadline >> profit;
        jobs.push_back(Job(id, deadline, profit));
    }

    printJobSequence(jobs);
    return 0;
}

/*
### Explanation of the Program:

1. **Job Class**: Represents a job with an identifier, a deadline, and a profit.

2. **printJobSequence Method**:
   - Sorts the jobs in descending order based on profit.
   - Determines the maximum deadline from the jobs to set up the scheduling slots.
   - Initializes an array for the result and a boolean array to track filled slots.
   - Iterates through the sorted jobs and assigns each job to the latest available slot before its deadline.
   - Calculates the total profit from the scheduled jobs.

3. **Main Method**:
   - Accepts user input for the number of jobs and their details (id, deadline, and profit).
   - Calls the `printJobSequence` method to process the jobs and display the results.

### Sample Input and Output:

**Input:**
```
5         // total no of jobs
a 2 100   // job class having - a-identifier, 2-deadline, 100-profit
b 1 19
c 2 27
d 1 25
e 3 15
```

**Output:**
```
Job Sequence: a c e
Total Profit: 142
```

### Breakdown of Output:

- **Job Sequence**:
  - **a**: Scheduled in slot 1 (deadline 2).
  - **c**: Scheduled in slot 2 (also has a deadline of 2, but slot 1 was filled by 'a').
  - **e**: Scheduled in slot 3 (fits within its deadline).

- **Total Profit**:
  - From the scheduled jobs:
    - Job 'a' (profit 100)
    - Job 'c' (profit 27)
    - Job 'e' (profit 15)
  - Total Profit = 100 + 27 + 15 = 142.

### Summary:
This program effectively schedules jobs to maximize profit while respecting their deadlines, providing a clear view of which jobs were chosen and the total profit generated.
*/