#include <iostream>
#include <vector>

using std::vector;
using std::cout;
using std::cin;
using std::endl;


int main ()
{
    int n,m;
    // n : nodes , m : edges
    cin >> n >> m ;

    vector<vector<int>> adj(n+1)(m+1);

    //int adj[n+1][m+1] = {0};
    // take adj[n][m] for 0 based indexing
    for (int i = 0; i < m ; i++){
        int u,v;
        cin >> u >> v;
        adj[u][v] = 1;
        adj[v][u] = 1;
    }

    // Printing the matrix
    for (int i = 0 ; i < n+1 ; i++){
        for (int j = 0; j < n+1 ; j++) {
            cout << adj[i][j] << " ";
        }
        cout << endl;

    }
    return 0;
}
