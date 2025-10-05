#include<bits/stdc++.h>
using namespace std;

bool isSafe(int i, int j, vector<vector<int>> &arr) {
    return
        i >= 0 && i < arr.size() &&
        j >= 0 && j < arr[i].size() &&
        arr[i][j] == 1;
}

int dx[4] = {-1, +1, +0, +0};
int dy[4] = {+0, +0, -1, +1};
int rottenOranges(vector<vector<int>> arr) {
    int n = arr.size();
    int m = arr[0].size();

    queue<pair<int, int>> q;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (arr[i][j] == 2) {
                q.push({i, j});
            }
        }
    }

    int result = 0;
    while (!q.empty()) {
        int sz = q.size();
        for (int _ = 0; _ < sz; _++) {
            pair<int, int> curr = q.front();
            q.pop();

            int i = curr.first;
            int j = curr.second;

            for (int k = 0; k < 4; k++) {
                int new_i = i + dx[k];
                int new_j = j + dy[k];
                if (isSafe(new_i, new_j, arr)) {
                    arr[new_i][new_j] = 2;
                    q.push({new_i, new_j});
                }
            }
        }
        result++;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (arr[i][j] == 1) {
                return -1;
            }
        }
    }
    return result == 0 ? 0 : result - 1;
}

int main() {
    cout << rottenOranges({{0, 1, 2},
                           {0, 1, 2},
                           {2, 1, 1}}) << endl;
    
    cout << rottenOranges({{2, 2, 0, 1}}) << endl;

    cout << rottenOranges({{0, 1, 2, 1, 1},
                           {0, 1, 1, 1, 1},
                           {0, 2, 1, 1, 1},
                           {0, 2, 0, 0, 2}}) << endl;
    
    cout << rottenOranges({{2, 2, 2, 0}}) << endl;

    cout << rottenOranges({{0, 0, 0, 0}}) << endl;
}