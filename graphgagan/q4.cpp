#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

int main() {
    int V, E;
    cin >> V >> E;

    vector<vector<pair<int,int>>> adj(V);
    for (int i = 0; i < E; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    vector<int> key(V, INT_MAX), parent(V, -1), vis(V, 0);
    key[0] = 0;

    priority_queue<
        pair<int,int>,
        vector<pair<int,int>>,
        greater<pair<int,int>>
    > pq;

    pq.push({0, 0});

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();
        vis[u] = 1;

        for (auto p : adj[u]) {
            int v = p.first, w = p.second;

            if (!vis[v] && w < key[v]) {
                key[v] = w;
                parent[v] = u;
                pq.push({key[v], v});
            }
        }
    }

    int total = 0;
    for (int i = 1; i < V; i++) {
        cout << parent[i] << " - " << i << endl;
        total += key[i];
    }

    cout << total;
}