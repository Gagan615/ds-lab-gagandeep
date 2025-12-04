#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Edge {
    int u, v, w;
};

int findp(int x, vector<int>& parent) {
    if (parent[x] == x) return x;
    return parent[x] = findp(parent[x], parent);
}

int main() {
    int V, E;
    cin >> V >> E;

    vector<Edge> edges(E);
    for (int i = 0; i < E; i++)
        cin >> edges[i].u >> edges[i].v >> edges[i].w;

    sort(edges.begin(), edges.end(), [](Edge a, Edge b) {
        return a.w < b.w;
    });

    vector<int> parent(V);
    for (int i = 0; i < V; i++) parent[i] = i;

    int total = 0;

    for (auto e : edges) {
        int pu = findp(e.u, parent);
        int pv = findp(e.v, parent);

        if (pu != pv) {
            parent[pv] = pu;
            total += e.w;
            cout << e.u << " - " << e.v << endl;
        }
    }

    cout << total;
}