#include<bits/stdc++.h>
using namespace std;

// Plain Rec:
// TC: O(3^(max(n, m)))
// AS: O(max(n, m))

// DP:
// TC: O(n*m)
// AS: O(n*m)
int editDistanceUtil(int i, int j, string &A, string &B, vector<vector<int>> &memo) {
    if (i == A.length()) {
        // We need to insert some characters into the empty string A.
        return B.length() - j;
    }
    if (j == B.length()) {
        // We need to delete all the remaining characters from A.
        return A.length() - i;
    }
    if (memo[i][j] != -1) {
        return memo[i][j];
    }

    if (A[i] == B[j]) {
        memo[i][j] = editDistanceUtil(i + 1, j + 1, A, B, memo);
        return memo[i][j];
    }

    int insert = 1 + editDistanceUtil(i, j + 1, A, B, memo);
    int del = 1 + editDistanceUtil(i + 1, j, A, B, memo);
    int replace = 1 + editDistanceUtil(i + 1, j + 1, A, B, memo);

    memo[i][j] = min({insert, del, replace});
    return memo[i][j];
}

int editDistance(string A, string B) {
    int n = A.length();
    int m = B.length();
    vector<vector<int>> memo(n, vector<int> (m, -1));
    return editDistanceUtil(0, 0, A, B, memo);
}

int main() {
}