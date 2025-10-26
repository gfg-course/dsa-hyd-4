#include<bits/stdc++.h>
using namespace std;

class Job {
    public:
    int id;
    int profit;
    int deadline;

    Job(int id, int deadline, int profit) {
        this->id = id;
        this->profit = profit;
        this->deadline = deadline;
    }
};

bool profitsComp(Job* &a, Job* &b) {
    if (a->profit == b->profit) {
        return a->deadline > b->deadline;
    }

    return a->profit > b->profit;
}

// TC: O(n*log(n) + n*max_deadline)
// AS: O(maxDeadline)
pair<int, int> jobSequencing(vector<Job*> jobs) {
    int n = jobs.size();
    sort(jobs.begin(), jobs.end(), profitsComp);

    int maxDeadline = 0;
    for (int i = 0; i < n; i++) {
        maxDeadline = max(maxDeadline, jobs[i]->deadline);
    }

    vector<int> slots(maxDeadline, -1);

    int numJobs = 0, maxProfit = 0;
    for (int i = 0; i < n; i++) {
        int j = jobs[i]->deadline - 1;
        while (j >= 0) {
            if (slots[j] == -1) {
                slots[j] = jobs[i]->id;
                numJobs++;
                maxProfit += jobs[i]->profit;
                break;
            }
            j--;
        }
    }

    return {numJobs, maxProfit};
}


// ------------------------------------

bool deadlineComp(Job* &a, Job* &b) {
    if (a->deadline == b->deadline) {
        return a->profit > b->profit;
    }

    return a->deadline < b->deadline;
}

// TC: O(n*log(n))
// AS: O(n)
pair<int, int> jobSequencingOptimal(vector<Job*> jobs) {
    int n = jobs.size();

    sort(jobs.begin(), jobs.end(), deadlineComp);

    int numJobs = 0, maxProfit = 0;
    priority_queue<int, vector<int>, greater<int>> profits; // min-heap of profits.

    for (int i = 0; i < n; i++) {
        if (jobs[i]->deadline > numJobs) {
            numJobs++;
            maxProfit += jobs[i]->profit;
            profits.push(jobs[i]->profit);
        } else {
            if (jobs[i]->profit > profits.top()) {
                maxProfit += (jobs[i]->profit - profits.top());
                profits.pop();
                profits.push(jobs[i]->profit);
            }
        }
    }

    return {numJobs, maxProfit};

}


int main() {

    pair<int, int> res = jobSequencingOptimal({new Job(1, 4, 20),
                                        new Job(2, 1, 10),
                                        new Job(3, 1, 40),
                                        new Job(4, 1, 30)});

    pair<int, int> res2 = jobSequencingOptimal({new Job(1, 2, 100),
                                        new Job(2, 1, 19),
                                        new Job(3, 2, 27),
                                        new Job(4, 1, 25),
                                        new Job(5, 1, 15)});
    
    cout << res.first << " " << res.second << endl;
    cout << res2.first << " " << res2.second << endl;
}