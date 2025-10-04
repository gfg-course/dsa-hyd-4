#include<bits/stdc++.h>
using namespace std;

int dx[8] = {-1, -2, -2, -1, +1, +2, +2, +1};
int dy[8] = {-2, -1, +1, +2, +2, +1, -1, -2};

bool isSafe(int i, int j, int n, vector<vector<bool>> &vis) {
    return
        i >= 1 && i <= n &&
        j >= 1 && j <= n &&
        !vis[i][j];
}

// V = n*n 
// E = <8*n*n
// TC: O(n*n)
// AS: O(n*n)
int stepsByKnight(int n, pair<int, int> sourcePos, pair<int, int> targetPos) {

    vector<vector<bool>> vis(n + 1, vector<bool> (n + 1, false));

    queue<pair<int, int>> q;
    q.push(sourcePos);
    vis[sourcePos.first][sourcePos.second] = true;

    int result = 0;
    while (!q.empty()) {
        int sz = q.size();
        for (int _ = 0; _ < sz; _++) {
            
            pair<int, int> curr = q.front();
            q.pop();

            int i = curr.first;
            int j = curr.second;

            if (i == targetPos.first && j == targetPos.second) {
                return result;
            }
            // dist[i][j] = result;

            for (int k = 0; k < 8; k++) {
                int new_i = i + dx[k];
                int new_j = j + dy[k];

                if (isSafe(new_i, new_j, n, vis)) {
                    q.push({new_i, new_j});
                    vis[new_i][new_j] = true;
                }
            }
        }
        result++;
    }

    return result;
}

int main() {
    cout << stepsByKnight(3, {3, 3}, {1, 2}) << endl;
    cout << stepsByKnight(6, {4, 5}, {1, 1}) << endl;
}