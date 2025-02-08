

// Graph is a collection of nodes or vertices (V) and edges (E) between them. We can represent the graph using adjacency matrix.

// Steps to represent a graph using adjacency matrix:
// 1. Create a 2D array of size VxV (where V is the number of vertices in the graph).
// 2. Initialize all the values in the matrix as 0.
// 3. For each edge (u, v), set mat[u][v] = 1 and mat[v][u] = 1.

// Pros:
// 1. Space efficient for representing dense graphs.
// 2. Edge weight can be stored in the matrix.

// Cons:
// 1. Space complexity is O(V^2).
// 2. Iterating over all edges takes O(V^2) time.

// Space Complexity: O(V^2)
// Time Complexity: O(1) for checking if there is an edge between two nodes.
 

#include <iostream>
using namespace std;

const int MAX = 100;
int mat[MAX][MAX] = {0};

void addEdge(int i, int j)
{   
    mat[i][i] = 1;  // for self loop
    mat[j][j] = 1;  // for self loop

    mat[i][j] = 1;
    mat[j][i] = 1;  // for undirected graph
}

void displayMatrix(int n)
{
    for (int i = 1; i <=n; i++)
    {
        for (int j = 1; j <=n; j++)
            cout << mat[i][j] << " ";
        cout << endl;
    }
}

int main()
{
    int n;
    cout << "Enter the number of nodes: " << endl;
    cin >> n;

    int m;
    cout << "Enter the number of edges: " << endl;
    cin >> m;
    
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        addEdge(u, v);
    }

    cout << "Adjacency Matrix Representation" << endl;
    displayMatrix(n);

    return 0;
}
