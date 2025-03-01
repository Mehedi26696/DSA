


#include <iostream>
#include <vector>
#include <stack>
 

using namespace std;

class Graph {
    int V;
    vector<int> *adj;

public:
    Graph(int V) {
        this->V = V;
        adj = new vector<int>[V];
    }

    void addEdge(int u, int v) {
        adj[u].push_back(v);
    }

    void DFS(int v) {
        vector<bool> visited(V, false);
        DFSVisit(v, visited);
    }

    void DFSVisit(int v, vector<bool> &visited) {
        visited[v] = true;
        cout << v << " ";
        for (int u : adj[v]) {
            if (!visited[u]) {
                DFSVisit(u, visited);
            }
        }
    }

    void stackDFS(int v) {
        vector<bool> visited(V, false);
        stack<int> s;
        s.push(v);
        visited[v] = true;
        while (!s.empty()) {
            v = s.top();
            cout << v << " ";
            s.pop();
            for (int u : adj[v]) {
                if (!visited[u]) {
                    s.push(u);
                    visited[u] = true;
                }
            }
        }
    }


};

int main() {
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);
 
    cout << "Depth First Traversal (starting from vertex 2): ";
    g.DFS(2);
    cout << endl;

    cout << "Depth First Traversal using stack (starting from vertex 2): ";
    g.stackDFS(2);
    cout << endl;
 
    return 0;
}

// Time Complexity: O(V + E), where V is the number of vertices and E is the number of edges in the graph.
// Space Complexity: O(V), where V is the number of vertices in the graph.