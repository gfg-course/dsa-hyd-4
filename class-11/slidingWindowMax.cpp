#include<bits/stdc++.h>
using namespace std;

// TC: O(n)
// AS: O(k)
vector<int> slidingWindowMax(vector<int> arr, int k) {
    int n = arr.size();
    if (k == 1) {
        return arr;
    }

    vector<int> result;

    deque<int> dq;
    for (int i = 0; i < k; i++) {
        while (!dq.empty() && arr[dq.back()] <= arr[i]) {
            dq.pop_back();
        }

        dq.push_back(i);
    }

    result.push_back(arr[dq.front()]);

    for (int i = k; i < n; i++) {
        while (!dq.empty() && arr[dq.back()] <= arr[i]) {
            dq.pop_back();
        }

        dq.push_back(i);

        if (dq.front() <= i - k) {
            dq.pop_front();
        }

        result.push_back(arr[dq.front()]);
    }

    return result;
}

int main() {
    vector<int> result = slidingWindowMax({1, 2, 3, 1, 4, 5, 2, 1, 0}, 3);
    
    for (int i : result) {
        cout << i << " ";
    }
}