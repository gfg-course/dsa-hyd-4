#include<bits/stdc++.h>
using namespace std;

// TC: O(n*log(k))
// AS: O(k)
int kthLargestElement(vector<int> arr, int k) {
    if (arr.size() < k) {
        return -1;
    }

    priority_queue<int, vector<int>, greater<int>> pq; // min-heap
    
    for (int i = 0; i < k; i++) {
        pq.push(arr[i]);
    }

    for (int i = k; i < arr.size(); i++) {
        if (arr[i] > pq.top()) {
            pq.pop();
            pq.push(arr[i]);
        }
    }

    return pq.top();
}

int kthLargestElementWithMaxHeapHack(vector<int> arr, int k) {
    if (arr.size() < k) {
        return -1;
    }

    priority_queue<int> pq;
    
    for (int i = 0; i < k; i++) {
        pq.push(-1*arr[i]);
    }

    for (int i = k; i < arr.size(); i++) {
        if (arr[i] > (-1*pq.top())) {
            pq.pop();
            pq.push(-1*arr[i]);
        }
    }

    return -1*pq.top();
}

int main() {
    cout << kthLargestElement({3, 5, 4, 4, 9}, 3) << endl;
    cout << kthLargestElement({3, 5, 4, 4, 9}, 1) << endl;
    cout << kthLargestElement({3, 5, 4, 4, 9}, 5) << endl;
    cout << kthLargestElement({3, 5, 4, 4, 9}, 50) << endl;

    cout << kthLargestElementWithMaxHeapHack({3, 5, 4, 4, 9}, 3) << endl;
    cout << kthLargestElementWithMaxHeapHack({3, 5, 4, 4, 9}, 1) << endl;
    cout << kthLargestElementWithMaxHeapHack({3, 5, 4, 4, 9}, 5) << endl;
    cout << kthLargestElementWithMaxHeapHack({3, 5, 4, 4, 9}, 50) << endl;
}