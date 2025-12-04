#include <iostream>
#include <vector>
using namespace std;

void dfs(int node, vector<vector<int>>& adj, vector<int>& vis) {
    vis[node] = 1;
    cout << node << " ";

    for (int x : adj[node])
        if (!vis[x]) dfs(x, adj, vis);
}

int main() {
    int V, E;
    cin >> V >> E;

    vector<vector<int>> adj(V);
    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int start;
    cin >> start;

    vector<int> vis(V, 0);
    dfs(start, adj, vis);
}