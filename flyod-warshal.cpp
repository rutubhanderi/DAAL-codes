#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9;
void printMatrix(const vector<vector<int>>& dist, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (dist[i][j] == INF)
                cout << setw(5) << "INF";
            else
                cout << setw(5) << dist[i][j];
        }
        cout << endl;
    }
}
void floydWarshall(vector<vector<int>>& dist, int n) {
    cout << "Initial distance matrix:" << endl;
    printMatrix(dist, n);
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (dist[i][k] != INF && dist[k][j] != INF && dist[i][j] > dist[i][k] + dist[k][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
        cout << "After considering vertex " << k + 1 << " as an intermediate vertex:" << endl;
        printMatrix(dist, n);
    }
}

int main() {
    int n;
    cout << "Enter the number of vertices: ";
    cin >> n;
    vector<vector<int>> graph(n, vector<int>(n));
    cout << "Enter the adjacency matrix (use " << INF << " for no direct path):" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> graph[i][j];
            if (i != j && graph[i][j] == 0) {
                graph[i][j] = INF;
            }
        }
    }
    floydWarshall(graph, n);

    return 0;
}
