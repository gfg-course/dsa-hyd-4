#include<bits/stdc++.h>
using namespace std;

// TC: O(n^2)
// AS: O(1)
bool tripletSum(vector<int> arr, int target) {

    int n = arr.size();

    sort(arr.begin(), arr.end());

    for (int i = 0; i < n; i++) {
        int newTarget = target - arr[i];
        int left = i + 1, right = n - 1;
        while (left < right) {
            if (arr[left] + arr[right] == newTarget) {
                return true;
            }
            if (newTarget > arr[left] + arr[right]) {
                left++;
            } else {
                right--;
            }
        }
    }

    return false;
}

int main() {
    cout << tripletSum({1, 4, 45, 6, 10, 8}, 13) << endl;
    cout << tripletSum({1, 4, 45, 6, 10, 8}, 30) << endl;
}