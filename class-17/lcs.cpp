#include<bits/stdc++.h>
using namespace std;

int lcsUtil(int i, int j, string &s1, string &s2, vector<vector<int>> &memo) {
    if (i == s1.length() || j == s2.length()) {
        return 0;
    }
    if (memo[i][j] != -1) {
        return memo[i][j];
    }

    if (s1[i] == s2[j]) {
        memo[i][j] = 1 + lcsUtil(i + 1, j + 1, s1, s2, memo);
        return memo[i][j];
    }

    memo[i][j] = max(lcsUtil(i + 1, j, s1, s2, memo), lcsUtil(i, j + 1, s1, s2, memo));
    return memo[i][j];
}


// Rec-> TC: O(2^(max(n, m))), AS: O(max(n, m))
// TC: O(n*m)
// AS: O(n*m)
int lcs(string s1, string s2) {
    int n = s1.length(), m = s2.length();
    vector<vector<int>> memo(n, vector<int> (m, -1));
    return lcsUtil(0, 0, s1, s2, memo);
}

int main() {
    cout << lcs("ABCDGH", "AEDFHR") << endl;
}