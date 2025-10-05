#include<bits/stdc++.h>
using namespace std;

vector<vector<pair<int, int>>> buildAdj(vector<vector<int>> &edges, int V) {
    vector<vector<pair<int, int>>> adj(V);

    for (vector<int> edge : edges) {
        int u = edge[0];
        int v = edge[1];
        int w = edge[2];

        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    return adj;
}

// TC: O(V*log(V) + E)
// AS: O(V)
vector<int> dijikstra(vector<vector<int>> edges, int V, int source) {
    vector<vector<pair<int, int>>> adj = buildAdj(edges, V);

    vector<int> dist(V, 1e9);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // Min-Heap

    dist[source] = 0;
    pq.push({dist[source], source});

    while (!pq.empty()) {
        pair<int, int> curr = pq.top();
        pq.pop();

        int distU = curr.first;
        int u = curr.second;

        for (pair<int, int> neighbor : adj[u]) {
            int v = neighbor.first;
            int distUV = neighbor.second;

            if (dist[v] > distU + distUV) {
                dist[v] = distU + distUV;
                pq.push({dist[v], v});
            }
        }
    }

    return dist;
}

int main() {

    vector<int> dist = dijikstra({{0, 1, 4},
                                  {0, 7, 8},
                                  {1, 7, 11},
                                  {1, 2, 8},
                                  {2, 8, 2},
                                  {2, 5, 4},
                                  {2, 3, 7},
                                  {3, 5, 14},
                                  {3, 4, 9},
                                  {4, 5, 10},
                                  {5, 6, 2},
                                  {6, 7, 1},
                                  {6, 8, 6},
                                  {7, 8, 7}}, 9, 0);

    for (int i : dist) {
        cout << i << endl;
    }
}