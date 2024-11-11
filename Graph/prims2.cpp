#include<bits/stdc++.h>
using namespace std;

class Graph {
private:
    int V;
    vector<vector<int> > matrix; 

public:
    Graph(int vertices) {
        V = vertices;
        matrix.resize(V, vector<int>(V, 0)); 
    }


    void addedge(int weight, int i, int j) {
        if (i < V && j < V) {
            matrix[i][j] = weight;
            matrix[j][i] = weight;
            return;
        }
        return; 
    }

    void printgraph() {
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                cout << matrix[i][j] << " ";
            }
            cout << endl;
        }
    }
    
    
     void primMST() {
        vector<int> key(V, INT_MAX);
        vector<bool> inMST(V, false); 
        vector<int> parent(V, -1);    

        key[0] = 0; 
        parent[0] = -1; 
        int totalWeight=0;

        for (int count = 0; count < V - 1; count++) {
            int u = -1;
            for (int v = 0; v < V; v++)
                if (!inMST[v] && (u == -1 || key[v] < key[u]))
                    u = v;

            inMST[u] = true; 	
            for (int v = 0; v < V; v++) {
                if (matrix[u][v] && !inMST[v] && matrix[u][v] < key[v]) {
                    parent[v] = u;
                    key[v] = matrix[u][v];
                }
            }
        }
        cout << "Edge \tWeight\n";
         for (int i = 1; i < V; i++) {
        cout << parent[i] << " - " << i << "\t" << matrix[i][parent[i]] << " \n";
        totalWeight += matrix[i][parent[i]]; 
    }

    cout << "Total Weight of MST: " << totalWeight << endl; 
    }
};

int main() {
    int vertices,noedges;
    cout << "Enter vertices: ";
    cin >> vertices;
    Graph g(vertices);
    cout<<"Enter number of edges you want to add:";
    cin>>noedges;
    while(noedges--){
    	int i,j,weight;
    	cout<<"\nEnter vertices:";
    	cin>>i>>j;
    	cout<<"\nEnter weight of edge:";
    	cin>>weight;
    	g.addedge(weight,i,j);	
	}
    g.printgraph();
    g.primMST();
    return 0;
}