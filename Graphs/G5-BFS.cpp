//{ Driver Code Starts
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        vector<int> bfs;
        int visited[V] = {0};
        queue<int> exp_q;
        exp_q.push(0); // We're staring with 0
        visited[0] = 1;

        while (exp_q.empty()!=1){
            int node = exp_q.front();
            exp_q.pop();
            bfs.push_back(node);

            for (auto x: adj[node]) {
                if (visited[x] == 0)
                {
                    exp_q.push(x);
                    visited[x] = 1;
                }

            }
        }
        return bfs;

    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >>

            E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            // 		adj[v].push_back(u);
        }
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.bfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends
