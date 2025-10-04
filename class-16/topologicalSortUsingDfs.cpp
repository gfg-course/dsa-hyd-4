#include<bits/stdc++.h>
using namespace std;

void dfsUtil(int u, vector<vector<int>> &adj, vector<bool> &vis, stack<int> &s) {
    
    vis[u] = true;
    for (int v : adj[u]) {
        if (!vis[v]) {
            dfsUtil(v, adj, vis, s);
        }
    }
    s.push(u);
}

// TC: O(V + E)
// AS: O(V)
vector<int> topologicalSort(vector<vector<int>> adj) {
    int V = adj.size();
    vector<bool> vis(V);
    for (int i = 0; i < V; i++) {
        vis[i] = false;
    }


    stack<int> s;
    for (int i = 0; i < V; i++) {
        if (!vis[i]) {
            dfsUtil(i, adj, vis, s);
        }
    }

    vector<int> result;
    while (!s.empty()) {
        result.push_back(s.top());
        s.pop();
    }
    return result;
}

int main() {
    vector<int> res = topologicalSort({{},
                                       {3},
                                       {3},
                                       {},
                                       {0,1},
                                       {0,2}});
    
    for (int i : res) {
        cout << i << " ";
    }
}