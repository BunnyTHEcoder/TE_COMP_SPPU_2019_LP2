#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct Job {
    int id, deadline, profit;
};

bool compareJobs(Job a, Job b) {
    return a.profit > b.profit;
}

void jobScheduling(vector<Job>& jobs, int n) {
    vector<int> result(n, -1);
    vector<bool> slot(n, false);
    for (int i = 0; i < n; i++) {
        for (int j = min(n, jobs[i].deadline) - 1; j >= 0; j--) {
            if (!slot[j]) {
                result[j] = i;
                slot[j] = true;
                break;
            }
        }
    }

    int total_profit = 0;
    for (int i = 0; i < n; i++) {
        if (slot[i]) {
            total_profit += jobs[result[i]].profit;
        }
    }

    cout << "Jobs scheduled: ";
    for (int i = 0; i < n; i++) {
        if (slot[i]) {
            cout << jobs[result[i]].id << " ";
        }
    }
    cout << endl;

    cout << "Total profit: " << total_profit << endl;
}

int main() {
    // 5
    // 1 2 20
    // 2 2 15
    // 3 1 10
    // 4 3 5
    // 5 3 1
    int n;
    cout << "Enter number of jobs: ";
    cin >> n;

    vector<Job> jobs(n);

    cout << "Enter jobs (id deadline profit): " << endl;
    for (int i = 0; i < n; i++) {
        cin >> jobs[i].id >> jobs[i].deadline >> jobs[i].profit;
    }

    sort(jobs.begin(), jobs.end(), compareJobs);

    jobScheduling(jobs, n);

    return 0;
}