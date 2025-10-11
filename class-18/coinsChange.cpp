#include<bits/stdc++.h>
using namespace std;

// TC: O(n*value)
// AS: O(n*value)
int minCoinsUtil(int i, vector<int> &coins, int value, vector<vector<int>> &memo) {
    if (value == 0) {
        return 0;
    }
    if (i == coins.size()) {
        return 1e9;
    }
    if (memo[i][value] != -1) {
        return memo[i][value];
    }

    // exclude.
    int result = minCoinsUtil(i + 1, coins, value, memo);

    // include, if possible.
    if (value >= coins[i]) {
        result = min(result, 1 + minCoinsUtil(i, coins, value - coins[i], memo));
    }

    memo[i][value] = result;
    return result;
}

int minCoins(vector<int> coins, int value) {
    int n = coins.size();
    vector<vector<int>> memo(n, vector<int> (value + 1, -1));
    int result = minCoinsUtil(0, coins, value, memo);
    if (result >= 1e9) {
        return -1;
    }
    return result;
}

int main() {
    cout << minCoins({3, 6, 3}, 5) << endl;
    cout << minCoins({2, 5, 3, 6}, 10) << endl;
}