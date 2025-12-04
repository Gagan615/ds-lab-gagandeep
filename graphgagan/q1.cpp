#include <iostream>
#include <vector>
#include <queue>
using namespace std;

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
    queue<int> q;

    q.push(start);
    vis[start] = 1;

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        cout << node << " ";

        for (int x : adj[node]) {
            if (!vis[x]) {
                vis[x] = 1;
                q.push(x);
            }
        }
    }
}