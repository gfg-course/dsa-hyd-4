#include<bits/stdc++.h>
using namespace std;

// TC: O(n)
// AS: O(1)
int getSmallestPositiveMissingNumber(vector<int> arr) {
    int n = arr.size();

    for (int i = 0; i < n; i++) {
        if (arr[i] < 1) {
            arr[i] = n + 1;
        }
    }

    for (int i = 0; i < n; i++) {
        int bucketIndex = abs(arr[i]) - 1;

        // Make the bucket negative
        if (bucketIndex < n && arr[bucketIndex] > 0) {
            arr[bucketIndex] *= -1;
        }
    }

    for (int i = 0; i < n; i++) {
        if (arr[i] > 0) {
            return i + 1;
        }
    }

    return n + 1;
}

int main() {

    cout << getSmallestPositiveMissingNumber({1, 2, 3, 4, 5}) << endl;
    cout << getSmallestPositiveMissingNumber({0, -10, 1, 3, -20}) << endl;
}