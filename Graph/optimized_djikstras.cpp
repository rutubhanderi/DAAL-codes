#include <bits/stdc++.h>
using namespace std;

void dijkstra(int start, const vector<vector<pair<int, int>>> &graph, int V) {
    vector<int> dist(V, INT_MAX);  
    dist[start] = 0;         
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, start});  

    while (!pq.empty()) {
        int u = pq.top().second;  
        int d = pq.top().first;    
        pq.pop();

        if (d > dist[u]) continue;

        for (const auto &neighbor : graph[u]) {
            int v = neighbor.first;  
            int weight = neighbor.second;  

            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;  
                pq.push({dist[v], v});      
            }
        }
    }

    for (int i = 0; i < V; ++i) {
        if (dist[i] == INT_MAX)
            cout << "Node " << i << ": Unreachable\n";
        else
            cout << "Node " << i << ": " << dist[i] << "\n";
    }
}

int main() {
    int V, E, start;
    cout << "Enter the number of vertices and edges: ";
    cin >> V >> E;

    vector<vector<pair<int, int>>> graph(V);  
    graph.reserve(V);

    cout << "Enter the edges (source, destination, weight):\n";
    for (int i = 0; i < E; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
        graph[v].push_back({u, w});  
    }

    cout << "Enter the starting node: ";
    cin >> start;

    dijkstra(start, graph, V);

    return 0;
}
