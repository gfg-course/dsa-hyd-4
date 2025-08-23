#include<bits/stdc++.h>
using namespace std;

// TC: O(n)
// AS: O(n)
int getMaxSumFromSubarray(vector<int> arr) {

    int n = arr.size();
    vector<int> maxTillHere(n);

    maxTillHere[0] = arr[0];
    int result = arr[0];

    for (int i = 1; i < n; i++) {
        maxTillHere[i] = max(arr[i], maxTillHere[i - 1] + arr[i]);
        result = max(result, maxTillHere[i]);
    }

    return result;
}

// TC: O(n)
// AS: O(1)
int getMaxSumFromSubarrayOptimal(vector<int> arr) {

    int n = arr.size();

    int maxTillHere = arr[0];
    int result = arr[0];

    for (int i = 1; i < n; i++) {
        maxTillHere = max(arr[i], maxTillHere + arr[i]);
        result = max(result, maxTillHere);
    }

    return result;
}

int main() {
    cout << getMaxSumFromSubarrayOptimal({-1, 2, 3, -9, 5}) << endl;
}