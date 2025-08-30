#include<bits/stdc++.h>
using namespace std;

// TC: O(n^2)
// AS: O(1)
bool checkSubarrayWith0SumBruteForce(vector<int> arr) {
    int n = arr.size();

    for (int i = 0; i < n; i++) {
        int sum = 0;
        for (int j = i ; j < n; j++) {
            sum += arr[j];
            if (sum == 0) {
                return true;
            }
        }
    }
    return false;
}

// TC: O(n)
// AS: O(n)
bool checkSubarrayWith0SumUsingHashMaps(vector<int> arr) {
    int n = arr.size();

    unordered_map<int, bool> prefixSums;
    int sum = 0;

    prefixSums[0] = true;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
        if (prefixSums[sum] == true) {
            return true;
        }
        prefixSums[sum] = true;
    }

    return false;
}
 
int main() {
    cout << checkSubarrayWith0SumUsingHashMaps({4, 2, -3, 1, 6}) << endl;
    cout << checkSubarrayWith0SumUsingHashMaps({1, 2, 0, 3}) << endl;
    cout << checkSubarrayWith0SumUsingHashMaps({1, 2, -5, -6}) << endl;
    cout << checkSubarrayWith0SumUsingHashMaps({1, 2, -3, 10}) << endl;
}