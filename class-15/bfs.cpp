#include<bits/stdc++.h>
using namespace std;

// TC: O(V + E)
// AS: O(V)
vector<int> bfs(vector<vector<int>> adj, int source) {

    int V = adj.size();
    vector<bool> vis(V, false);
    vector<int> res;

    queue<int> q;
    q.push(source);
    vis[source] = true;

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        res.push_back(u);

        for (int v : adj[u]) {
            if (!vis[v]) {
                q.push(v);
                vis[v] = true;
            }
        }
    }

    return res;
}

int main() {

    vector<int> res = bfs({{1, 2},
                           {0, 3},
                           {0, 3, 4},
                           {1, 2, 4},
                           {2, 3}}, 0);
    
    for (int i : res) {
        cout << i << " ";
    }
}