#include<bits/stdc++.h>
using namespace std;

bool isSafe(int i, int j, vector<vector<int>> &arr) {
    return
        i >= 0 && i < arr.size() &&
        j >= 0 && j < arr[i].size() &&
        arr[i][j] == 1;
}

int dx[8] = {-1, -1, -1, +0, +1, +1, +1, +0};
int dy[8] = {-1, +0, +1, +1, +1, +0, -1, -1};
void dfs(int i, int j, vector<vector<int>> &arr) {

    arr[i][j] = 0;

    for (int k = 0; k < 8; k++) {
        int new_i = i + dx[k];
        int new_j = j + dy[k];
        if (isSafe(new_i, new_j, arr)) {
            dfs(new_i, new_j, arr);
        }
    }
}

// V = n*m
// E = 8*n*m
// TC: O(n*m)
// AS: O(n*m)
int countIslands(vector<vector<int>> arr) {

    int n = arr.size();
    int m = arr[0].size();

    int result = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (arr[i][j] == 1) {
                result++;
                dfs(i, j, arr);
            }
        }
    }

    return result;
}

int main() {
}