#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Structure to represent an edge
struct Edge {
    int src, dest, weight;
};

// Structure to represent a disjoint set
struct DisjointSet {
    vector<int> parent, rank;

    DisjointSet(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int find(int u) {
        if (u != parent[u]) {
            parent[u] = find(parent[u]);
        }
        return parent[u];
    }

    void merge(int x, int y) {
        x = find(x);
        y = find(y);

        if (rank[x] > rank[y]) {
            parent[y] = x;
        } else {
            parent[x] = y;
        }

        if (rank[x] == rank[y]) {
            rank[y]++;
        }
    }
};

// Function to implement Kruskal's algorithm
vector<Edge> kruskal(vector<Edge>& edges, int V) {
    vector<Edge> result;
    
    // Sort edges by weight
    sort(edges.begin(), edges.end(), [](Edge a, Edge b) {
        return a.weight < b.weight;
    });

    DisjointSet ds(V);

    for (Edge e : edges) {
        int set_u = ds.find(e.src);
        int set_v = ds.find(e.dest);

        if (set_u != set_v) {
            result.push_back(e);
            ds.merge(set_u, set_v);
        }
    }

    return result;
}

int main() {
    int V = 4;  // Number of vertices
    vector<Edge> edges = {
        {0, 1, 10},
        {0, 2, 6},
        {0, 3, 5},
        {1, 3, 15},
        {2, 3, 4}
    };

    vector<Edge> mst = kruskal(edges, V);

    cout << "Edges in the Minimum Spanning Tree:" << endl;
    for (Edge e : mst) {
        cout << e.src << " - " << e.dest << " : " << e.weight << endl;
    }

    return 0;
}

