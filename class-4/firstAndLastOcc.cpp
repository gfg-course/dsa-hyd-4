#include<bits/stdc++.h>
using namespace std;

// TC: O(log(n))
// AS: O(1)
int getFirstOcc(vector<int> &arr, int target) {
    int low = 0, high = arr.size() - 1;

    int result = -1;

    while (low <= high) {
        int mid = (low + high) / 2;
        if (arr[mid] == target) {
            result = mid;
            high = mid - 1;
        } else if (target < arr[mid]) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    return result;
}

// TC: O(log(n))
// AS: O(1)
int getLastOcc(vector<int> &arr, int target) {
    int low = 0, high = arr.size() - 1;

    int result = -1;

    while (low <= high) {
        int mid = (low + high) / 2;
        if (arr[mid] == target) {
            result = mid;
            low = mid + 1;
        } else if (target < arr[mid]) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    return result;
}

// TC: O(log(n))
// AS: O(1)
pair<int, int> getFirstAndLastOcc(vector<int> arr, int target) {
    
    int firstOcc = getFirstOcc(arr, target);
    if (firstOcc == -1) {
        return {-1, -1};
    }
    return {firstOcc, getLastOcc(arr, target)};
}

int main() {
}