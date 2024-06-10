//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
    bool isCycleDFS(unordered_map<int, bool> &visited, int parent,vector<int>adjList[], int node)
{
    visited[node] = 1;
    for (auto val : adjList[node])
    {
        if (visited[val] == false)
        {
            bool ans = isCycleDFS(visited, node, adjList, val);
            if (ans == true)
                return true;
        }
        else if (parent != val)
        {
            // present
            return true;
        }
    }
    return false;
}
  public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(int n, vector<int> adj[]) {
        // Code here
        unordered_map<int,bool>visited;
        int i;
        for(i=0;i<n;i++)
        {
            if(!visited[i]) 
            {
                bool ans=isCycleDFS(visited,-1,adj,i);
                if(ans==true) 
                {
                    i=-1;
                    break;
                }
            }
        }
        if(i==-1) return 1;
        return 0;
        
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends