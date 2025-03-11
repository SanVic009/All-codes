#include <iostream>
#include <limits.h>
using namespace std;

class graph {
    int e;
    int n;
    int cost[20][20];

public:
    void create_adj_matrix();
    void display();
    void prims(int s);
};

void graph::create_adj_matrix() {
    int s, d, c;
    cout << "Enter the Number of Vertices: " << endl;
    cin >> n;
    cout << "Enter the number of Edges: " << endl;
    cin >> e;

    for (int i = 0; i < n; i++) { 
        for (int j = 0; j < n; j++) {
            if (i == j)
                cost[i][j] = 0; 
            else
                cost[i][j] = INT_MAX;
        }
    }

    for (int i = 0; i < e; i++) {
        cout << "Enter Source Vertex for Edge " << i << ": ";
        cin >> s;
        cout << "Enter Destination Vertex for Edge " << i << ": ";
        cin >> d;
        cout << "Enter the Cost of Edge " << i << ": ";
        cin >> c;

      
        s--;
        d--;
        
        cost[s][d] = c;
        cost[d][s] = c;
    }
}

void graph::display() {
    cout << "Adjacency Matrix:" << endl;
    for (int i = 0; i < n; i++) { 
        for (int j = 0; j < n; j++) {
            if (cost[i][j] == INT_MAX) {
                cout << " 0 ";
            } else {    
                cout << cost[i][j] << " ";
            }
        }
        cout << endl;
    }
}

void graph::prims(int s) {
    s--; 

    int nearest[20];
    int mincost = 0;
    int t[20][3]; 
   
    for (int i = 0; i < n; i++) {
        nearest[i] = s;
    }
    nearest[s] = -1;

    int r = 0;
    for (int i = 1; i < n; i++) { 
        int min = INT_MAX;
        int j = -1;

        for (int k = 0; k < n; k++) {
            if (nearest[k] != -1 && cost[k][nearest[k]] < min) {
                j = k;
                min = cost[k][nearest[k]];
            }
        }

        if (j == -1) {
            cout << "The Graph is not connected." << endl;
            return;
        }

        t[r][0] = nearest[j];
        t[r][1] = j;
        t[r][2] = min;
        r++;
        mincost += min;
        nearest[j] = -1;

        for (int k = 0; k < n; k++) {
            if (nearest[k] != -1 && cost[k][nearest[k]] > cost[k][j]) {
                nearest[k] = j;
            }
        }
    }

    cout << "Edges in the Minimum Spanning Tree:" << endl;
    for (int i = 0; i < r; i++) {
        cout << t[i][0] + 1 << " - " << t[i][1] + 1 << " with cost " << t[i][2] << endl;
    }

    cout << "Minimum Cost: " << mincost << endl;
}

// int main() {
//     graph g;
//     g.create_adj_matrix();
//     g.display();
//     int s;
//     cout << "Enter the Starting Vertex: " << endl;
//     cin >> s;
//     g.prims(s);
//     return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;

// // Structure to represent an edge
// typedef pair<int, int> pii;

// void primsAlgorithm(int V, vector<vector<pii>> &adj) {
//     priority_queue<pii, vector<pii>, greater<pii>> pq;
//     vector<int> key(V, INT_MAX);
//     vector<int> parent(V, -1);
//     vector<bool> inMST(V, false);

//     // Start with vertex 0
//     pq.push({0, 0}); // {weight, vertex}
//     key[0] = 0;

//     while (!pq.empty()) {
//         int u = pq.top().second;
//         pq.pop();

//         if (inMST[u]) continue;
//         inMST[u] = true;

//         for (auto &[weight, v] : adj[u]) {
//             if (!inMST[v] && weight < key[v]) {
//                 key[v] = weight;
//                 pq.push({weight, v});
//                 parent[v] = u;
//             }
//         }
//     }

//     // Printing the MST
//     cout << "Edge  \tWeight\n";
//     for (int i = 1; i < V; i++) {
//         cout << parent[i] << " - " << i << "\t" << key[i] << "\n";
//     }
// }

// int main() {
//     int V, E;
//     cout << "Enter number of vertices and edges: ";
//     cin >> V >> E;
    
//     vector<vector<pii>> adj(V);
    
//     cout << "Enter edges (u v weight):\n";
//     for (int i = 0; i < E; i++) {
//         int u, v, w;
//         cin >> u >> v >> w;
//         adj[u].push_back({w, v});
//         adj[v].push_back({w, u});
//     }
    
//     primsAlgorithm(V, adj);
//     return 0;
// }
