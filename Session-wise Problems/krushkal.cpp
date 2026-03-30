#include <bits/stdc++.h>
using namespace std;

class DSU {
public:
    vector<int> parent, rank;
    
    DSU(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for(int i = 0; i < n; i++)
            parent[i] = i;
    }

    int find(int x) {
        if(parent[x] != x)
            parent[x] = find(parent[x]); 
        return parent[x];
    }

    void unite(int x, int y) {
        int px = find(x);
        int py = find(y);
        if(px == py) return;
        // Union by rank
        if(rank[px] < rank[py])
            parent[px] = py;
        else if(rank[px] > rank[py])
            parent[py] = px;
        else {
            parent[py] = px;
            rank[px]++;
        }
    }
};

int main() {
    int n, m;
    cin >> n >> m; // n = nodes, m = edges

    vector<vector<int>> edges;

    for(int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back({w, u, v}); // store as (weight, u, v)
    }

    // Sort edges by weight
    sort(edges.begin(), edges.end());

    DSU dsu(n);
    int mst_weight = 0;

    for(auto &edge : edges) {
        int w = edge[0];
        int u = edge[1];
        int v = edge[2];

        if(dsu.find(u) != dsu.find(v)) {
            mst_weight += w;
            dsu.unite(u, v);
        }
    }

    cout << "MST Weight: " << mst_weight << endl;
}