

// Graph representation using adjacency list
// Graph is a collection of nodes or vertices (V) and edges (E) between them. We can represent the graph using adjacency list.
// Steps to represent a graph using adjacency list:
// 1. Create a map where key is the node and value is a list of nodes connected to it.
// 2. For each edge (u, v), add v to the list of u and u to the list of v.
// Pros:
// 1. Space efficient for representing sparse graphs.
// 2. Iterating over all edges takes O(V+E) time.
// Cons:
// 1. Space complexity is O(V+E).
// 2. Edge weight cannot be stored in the list.


// Space Complexity: O(V+E)
// Time Complexity: O(1) for checking if there is an edge between two nodes.
// Time Complexity: O(V) for adding a new edge.
// Time Complexity: O(V+E) for printing the graph.


#include <bits/stdc++.h>
using namespace std;

class Graph
{   
    public:
    map<int, list<int>> adj;

    void addEdge(int u, int v , bool direction)
    {
        // direction = 0 means undirected 
        // direction = 1 means directed
        adj[u].push_back(v);

        if(direction == 0){
            adj[v].push_back(u);
        }
         
    }

    void print(){
        for(auto i : adj){
            cout << i.first << " -> ";
            for(auto j : i.second){
                cout << j << " ";
            }
            cout << endl;
        }
    }

};

int main(){

    int n;
    cout<<"Enter the number of nodes: "<<endl;
    cin>>n;

    int m;

    cout<<"Enter the number of edges: "<<endl;

    cin>>m;

    Graph g;

    for(int i = 0; i < m; i++){
        int u, v;
        cin>>u>>v;
        // creating an undirected graph
        g.addEdge(u, v, 0);
    }

    // printing the graph

    g.print();
    return 0;
}