#include<bits/stdc++.h>
using namespace std;

void combinationSumUtil(int index, vector<int> &arr, int target, vector<int> &curr, vector<vector<int>> &result) {
    if (target == 0) {
        result.push_back(curr);
        return;
    }
    if (index == arr.size()) {
        return;
    }

    // Take arr[i] inside our current combination.
    if (arr[index] <= target) {
        curr.push_back(arr[index]);
        combinationSumUtil(index, arr, target - arr[index], curr, result);
        curr.pop_back();
    }

    // Skip arr[i].
    combinationSumUtil(index + 1, arr, target, curr, result);
}

vector<vector<int>> combinationSum(vector<int> arr, int target) {

    vector<vector<int>> result;
    vector<int> curr;

    combinationSumUtil(0, arr, target, curr, result);

    return result;
}

int main() {
    vector<vector<int>> result = combinationSum({2, 4, 6, 8}, 8);

    cout << result.size() << endl;
    for (int i = 0; i < result.size(); i++) {
        for (int j = 0; j < result[i].size(); j++) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
}