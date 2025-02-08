

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

const int MAX = 100;  
vector<int> adj[MAX];  // Adjacency list instead of a matrix

// BFS function
void bfs(int s, int n) {
    queue<int> q;
    vector<bool> visited(n + 1, false);

    visited[s] = true;
    q.push(s);

    while (!q.empty()) {
        int curr = q.front();
        q.pop();
        cout << curr << " ";

        for (int neighbor : adj[curr]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
}

// Function to add edges
void addEdge(int u, int v, int n) {
    if (u > n || v > n || u < 1 || v < 1) {
        cout << "Invalid edge: (" << u << ", " << v << ")" << endl;
        return;
    }
    adj[u].push_back(v);
    adj[v].push_back(u);  // Since it's an undirected graph
}

// Function to display adjacency list
void displayAdjList(int n) {
    cout << "Adjacency List Representation:\n";
    for (int i = 1; i <= n; i++) {
        cout << i << " -> ";
        for (int neighbor : adj[i]) {
            cout << neighbor << " ";
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
        int u, v;
        cin >> u >> v;
        addEdge(u, v, n);
    }

    // Display adjacency list
    displayAdjList(n);

    // Perform BFS from node 1
    cout << "BFS Traversal: ";
    bfs(1, n);
    cout << endl;

    return 0;
}

// Time Complexity: O(V + E), where V is the number of vertices and E is the number of edges in the graph.

// Space Complexity: O(V + E) + O(V) + O(V) ≈ O(V + E) for adjacency list and visited array.

