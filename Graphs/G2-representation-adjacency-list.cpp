#include <iostream>
#include <vector>
using std::cout;
using std::cin;
using std::endl;

int main ()
{
    int n, m;
    // n : Nodes, m : edges

    cin >> n >> m;
    int u,v;
    std::vector<int> adj[n+1]; // Array of vectors
    for (int i = 0; i < m; i++) {
        cin >> u >> v ;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // Printing the adjacency list
    for (int i = 0; i < m; i++) {
        auto val = adj[i];
        cout << "Row : " << i << "   :   ";
        for (int x : val){
            cout << x << " ";
        }
        cout << endl;

    }

    return 0;
}
