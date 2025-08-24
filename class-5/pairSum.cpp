#include<bits/stdc++.h>
using namespace std;

// TC: O(n)
// AS: O(1)
bool pairSum(vector<int> arr, int target) {

    int left = 0, right = arr.size() - 1;
    while (left < right) {
        if (arr[left] + arr[right] == target) {
            return true;
        }
        if (target > arr[left] + arr[right]) {
            left++;
        } else {
            right--;
        }
    }

    return false;
}

int main() {
    cout << pairSum({1, 2, 5, 6, 10}, 8) << endl;
    cout << pairSum({1, 2, 5, 6, 10}, 4) << endl;
    cout << pairSum({1, 2, 5, 6, 10}, -10) << endl;
    cout << pairSum({1, 2, 5, 6, 10}, 16) << endl;
    cout << pairSum({1, 2, 5, 6, 10}, 3) << endl;
}