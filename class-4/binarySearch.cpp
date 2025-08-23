#include<bits/stdc++.h>
using namespace std;

// TC: O(log(n))
// AS: O(1)
bool binarySearch(vector<int> arr, int target) {
    int low = 0, high = arr.size() - 1;

    while (low <= high) {
        int mid = (low + high) / 2;
        if (arr[mid] == target) {
            return true;
        }
        if (target < arr[mid]) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    return false;
}

int main() {
    cout << binarySearch({1}, 1) << endl;
    cout << binarySearch({3, 4, 7, 9, 11, 13, 15, 20}, 3) << endl;
    cout << binarySearch({3, 4, 7, 9, 11, 13, 15, 20}, 20) << endl;
    cout << binarySearch({3, 4, 7, 9, 11, 13, 15, 20}, 9) << endl;
    cout << binarySearch({3, 4, 7, 9, 11, 13, 15, 20}, 11) << endl;
    cout << binarySearch({3, 4, 7, 9, 11, 13, 15, 20}, 12) << endl;
}