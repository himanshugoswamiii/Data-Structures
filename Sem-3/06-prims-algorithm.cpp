// Completed : Working perfectly
#include<iostream>
#include <vector>
#include <queue>

using namespace std;

#define  pi pair<int, int>


int spanningTree(int V, vector<pi> adj[])
{
    // min Priority queue
    priority_queue<pi, vector<pi>, greater<pi>> pq;
    
    int vis[V] = {0}; // Visited array
    int sum = 0; // sum of MST
    
    pq.push({0,0}); // Starting with 0 which has 0 wt
    while(pq.empty()!=1){
        auto it = pq.top();
        pq.pop();
        
        int node = it.second;
        int wt = it.first;
        
        if(vis[node] == 1) continue;
        
        // Add node to the MST
        vis[node] = 1;
        sum += wt;

        cout << "Visited: " << node << " , edge wt: " << wt << " , net wt: " << sum << endl;

        
        // BFS
        for (auto it : adj[node]){
            int adjNode = it.first;
            int edW = it.second; // edge weight
            if(vis[adjNode] != 1){
                pq.push({edW, adjNode});
            }
        }
        
    }
    
    return sum;
    
}


int main()
{
    int V, E;
    cin >> V >> E;
    vector<pi> adj[V]; // Graph of 9 nodes
    // pi : pair
    // first : node, second : weight

    int u, v, w;

    for (int i = 0; i < E; i++) {
        cin >> u >> v >> w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }

    cout << spanningTree(V, adj) << endl;

    return 0;
}
