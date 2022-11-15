#include <iostream>
#include <queue>
#include <vector>

using namespace std;

void bfs_graph(vector<int> adj[], int V){
    cout << "BFS is : " << endl;
    queue<int> exp_q;
    int visited[V] = {0}; // don't worry about clang error

    int node = 0;

    cout << node << endl;
    visited[node] = 1;
    exp_q.push(node);

    while (exp_q.empty()!=1){
        node = exp_q.front();
        exp_q.pop();

        auto it = adj[node];
        for (int x  : it) {
            if (visited[x]!=1)
            {
                cout << x << endl;
                visited[x] = 1;
                exp_q.push(x);
            }
        }
    }

}

// Print the adjaceny list
void printGraph(vector<int> adj[], int V){

    cout << "Graph is : " << endl;
    for (int i = 0; i < V; i++) {
        auto it = adj[i];

        cout << i << " : ";

        for (int x: it) {
            cout << x << " " ;
        }

        cout << endl;
     
    }
}


int main ()
{
    // Graph
    int V, E; // V: No of vertices , E : Edges
    cin >> V;
    cin >> E;
    vector<int> adj[V];

    int parent, node;

    for (int i = 0; i < E; i++) {
        cin >> parent;
        cin >> node;

        // Undirected graph
        adj[parent].push_back(node);
        adj[node].push_back(parent);
        
    }

    printGraph(adj, V);

    bfs_graph(adj, V);

    return 0;
}
