//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
public:
    void dfs(int u, vector<vector<int>>& adj, vector<int>& visited, int& n, int &e) {
        visited[u] = 1;
        n++;
        e += adj[u].size();
        for (int &v: adj[u]) {
            if (!visited[v]) {
                dfs(v, adj, visited, n, e);
            } 
        }
    }     
 
    int findNumberOfGoodComponent(int V, vector<vector<int>>& adj) {
        int ans = 0;
        vector<int> visited(V+1, 0);
        
        for (int i=1; i<=V; i++) {
            if (!visited[i]) {
                int n = 0, e = 0;
                dfs(i, adj, visited, n, e);
                e = e / 2;
                if (e == n * (n - 1) / 2) ans++;
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