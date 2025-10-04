#include<bits/stdc++.h>
using namespace std;

bool isCyclicUtil(int u, int parent, vector<vector<int>> &adj, vector<bool> &vis) {

    vis[u] = true;
    for (int v : adj[u]) {
        if (vis[v] && v != parent) {
            return true;
        }
        if (!vis[v] && isCyclicUtil(v, u, adj, vis)) {
            return true;
        }
    }

    return false;
}

bool detectCycleInUndirectedGraph(vector<vector<int>> adj, int V) {

    vector<bool> vis(V, false);

    for (int i = 0; i < V; i++) {
        if (!vis[i] && isCyclicUtil(i, -1, adj, vis)) {
            return true;
        }
    }

    return false;
}

int main() {
}