#include<bits/stdc++.h>
using namespace std;

void dfsUtil(int u, vector<vector<int>> &adj, vector<bool> &vis, vector<int> &result) {
    if (vis[u]) {
        return;
    }

    vis[u] = true;
    result.push_back(u);

    for (int v : adj[u]) {
        dfsUtil(v, adj, vis, result);
    }
}

// TC: O(V + E)
// AS: O(V)
vector<int> dfs(vector<vector<int>> adj) {

    int V = adj.size();
    vector<bool> vis(V, false);
    vector<int> result;

    for (int i = 0; i < V; i++) {
        if (!vis[i]) {
            dfsUtil(i, adj, vis, result);
        }
    }
    return result;
}

int main() {

    vector<int> res = dfs({{1, 4},
                           {0, 4, 3, 2},
                           {1, 3},
                           {2, 1, 4},
                           {0, 1, 3}});
    
    for (int i : res) {
        cout << i << " ";
    }
}