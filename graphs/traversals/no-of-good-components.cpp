//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// Back-end complete function Template for C++

class Solution {
  public:
    // DFS function to traverse the graph
    void dfs(int u, int &vertices, int &edges, vector<vector<int>> &adj, vector<int> &visited) {
        visited[u] = 1;
        vertices++;
        edges += adj[u].size(); 
        for (int &v : adj[u]) {
            if (!visited[v]) {
                dfs(v, vertices, edges, adj, visited);
            }
        }
    }
    
    int findNumberOfGoodComponent(int V, vector<vector<int>>& adj) {
        int ans = 0;
        vector<int> visited(V + 1, 0);

        for (int i = 1; i <= V; i++) {
            if (!visited[i]) {
                int vertices = 0, edges = 0;
                dfs(i, vertices, edges, adj, visited);
                edges /= 2;
                if (edges == (vertices * (vertices - 1)) / 2) ans++;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int E, V;
        cin >> E >> V;
        vector<vector<int>> adj(V + 1, vector<int>());
        for (int i = 0; i < E; i++) {
            int u, v;

            cin >> u >> v;

            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;

        int res = obj.findNumberOfGoodComponent(V, adj);
        cout << res << "\n";
    }
    return 0;
}
// } Driver Code Ends