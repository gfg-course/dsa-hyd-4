#include<bits/stdc++.h>
using namespace std;

// Plain Rec:
// TC: O(2^n)
// AS: O(n)

// DP:
// TC: O(n*W)
// AS: O(n*W)
int maxValueUtil(int i, vector<int> &vals, vector<int> &wts, int W, vector<vector<int>> &memo) {
    if (i == vals.size() || W == 0) {
        return 0;
    }
    if (memo[i][W] != -1) {
        return memo[i][W];
    }

    // Exclude the current item.
    int result = maxValueUtil(i + 1, vals, wts, W, memo);

    // Include the current item, if possible.
    if (wts[i] <= W) {
        result = max(result, vals[i] + maxValueUtil(i + 1, vals, wts, W - wts[i], memo));
    }

    memo[i][W] = result;
    return memo[i][W];
}

int maxValue(vector<int> vals, vector<int> wts, int W) {

    int n = vals.size();
    vector<vector<int>> memo(n, vector<int> (W + 1, -1));

    return maxValueUtil(0, vals, wts, W, memo);
}

int main() {
    cout << maxValue({60, 100, 120}, {10, 20, 30}, 50) << endl;
    cout << maxValue({60, 100, 120}, {10, 20, 50}, 50) << endl;
}