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

// TC: O(n*W)
// AS: O(n*W) -> HW is to Optimize this to O(W) 
int maxValueBottomUp(vector<int> vals, vector<int> wts, int W) {

    int n = vals.size();
    vector<vector<int>> dp(n + 1, vector<int> (W + 1));

    // Cater to the base cases (logically).
    for (int i = 0; i <= n; i++) {
        dp[i][0] = 0;
    }
    for (int j = 0; j <= W; j++) {
        dp[0][j] = 0;
    }

    // Fill the rest of the table.
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= W; j++) {
            // Exclude.
            dp[i][j] = dp[i - 1][j]; 
            
            // Include, if possible.
            if (wts[i - 1] <= j) {
                dp[i][j] = max(dp[i][j], vals[i - 1] + dp[i - 1][j - wts[i - 1]]);
            }
        }
    }

    return dp[n][W];
}

int main() {
    cout << maxValueBottomUp({60, 100, 120}, {10, 20, 30}, 50) << endl;
    cout << maxValueBottomUp({60, 100, 120}, {10, 20, 50}, 50) << endl;
}