#include<bits/stdc++.h>
using namespace std;

// TC: O(n)
// AS: O(1)
int removeDuplicates(vector<int> &arr) {

    int n = arr.size();
    int left = 0, right = 0;
    while (right < n) {
        arr[left] = arr[right];
        while (right < n && arr[right] == arr[left]) {
            right++;
        }
        left++;
    }

    return left;
}

int main() {

    vector<int> arr = {1, 1, 2, 2, 3};
    int n = removeDuplicates(arr);
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
}