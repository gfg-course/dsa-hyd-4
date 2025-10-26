#include<bits/stdc++.h>
using namespace std;

// Rec BF:
// TC: O(4^(n/2))
// AS: O(n/2) = O(n)

// DP:
// TC: O(n^2)
// AS: O(n^2)
int maxAmountUtil(vector<int> &coins, int i, int j, vector<vector<int>> &memo) {
    if (i > j) {
        return 0;
    }
    if (memo[i][j] != -1) {
        return memo[i][j];
    }

    // Pick coins[i]
    int score1 = coins[i] + min(maxAmountUtil(coins, i + 2, j, memo), maxAmountUtil(coins, i + 1, j - 1, memo));

    // Pick coins[j]
    int score2 = coins[j] + min(maxAmountUtil(coins, i + 1, j - 1, memo), maxAmountUtil(coins, i, j - 2, memo));

    memo[i][j] = max(score1, score2);
    return memo[i][j];
}

int maxAmount(vector<int> coins) {
    int n = coins.size();
    vector<vector<int>> memo(n, vector<int> (n, -1));

    return maxAmountUtil(coins, 0, n - 1, memo);
}

int main() {

    cout << maxAmount({5, 3, 7, 10}) << endl;
    cout << maxAmount({8, 15, 3, 7}) << endl;
}