

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

const int MAX = 100;  
vector<pair<int, int>> adj[MAX];  // Adjacency list with weights

// BFS function (ignores weights, standard BFS)
void bfs(int s, int n) {
    queue<int> q;
    vector<bool> visited(n + 1, false);
    vector<int> dist(n + 1, -1);

    visited[s] = true;
    dist[s] = 0;
    q.push(s);

    while (!q.empty()) {
        int curr = q.front();
        q.pop();
        cout << curr << " ";

        for (int i = 0; i < adj[curr].size(); i++) {  
            int neighbor = adj[curr][i].first;  // Access first element of pair
            int weight = adj[curr][i].second;  // Access second element of pair

            if (!visited[neighbor]) {
                visited[neighbor] = true;
                dist[neighbor] = dist[curr] +  weight;
                q.push(neighbor);
            }
        }
    }

    cout << "\nDistance of each node from source node:\n";
    for (int i = 1; i <= n; i++) {
        cout << "Node " << i << " : " << dist[i] << endl;
    }
}

// Function to add weighted edges
void addEdge(int u, int v, int weight, int n) {
    if (u > n || v > n || u < 1 || v < 1) {
        cout << "Invalid edge: (" << u << ", " << v << ")" << endl;
        return;
    }
    adj[u].push_back(make_pair(v, weight));  // Use make_pair() instead of {}
    adj[v].push_back(make_pair(u, weight));  // Undirected graph
}

// Function to display adjacency list
void displayAdjList(int n) {
    cout << "Adjacency List Representation:\n";
    for (int i = 1; i <= n; i++) {
        cout << i << " -> ";
        for (size_t j = 0; j < adj[i].size(); j++) {
            cout << "(" << adj[i][j].first << ", " << adj[i][j].second << ") ";
        }
        cout << endl;
    }
}

int main() {
    int n, m;
    cout << "Enter the number of nodes: ";
    cin >> n;
    cout << "Enter the number of edges: ";
    cin >> m;

    for (int i = 0; i < m; i++) {
        int u, v, weight;
        cout << "Enter edge (u, v, weight): ";
        cin >> u >> v >> weight;
        addEdge(u, v, weight, n);
    }

    // Display adjacency list
    displayAdjList(n);

    // Perform BFS from node 1
    cout << "BFS Traversal: ";
    bfs(1, n);
    cout << endl;

    return 0;
}
