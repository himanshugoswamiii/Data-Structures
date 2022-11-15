#include <iostream>
#include <vector>
using std::vector;
using std::cout;
using std::cin;
using std::endl;

int n, m;
void print(int (&arr)[n+1][m+1]){
    for (int j = 0; j < m; j++){
    cout << arr[0][j] << endl;
    }
}

int main ()
{
    int n,m;
    // n : nodes , m : edges
    cin >> n >> m ;

    int adj[n+1][m+1];
    // take adj[n][m] for 0 based indexing
    for (int i = 0; i < m ; i++){
        int u,v;
        cin >> u >> v;
        adj[u][v] = 1;
        adj[v][u] = 1;
    }

    print(adj);

    return 0;
}
