//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
    bool isCycleBFS(int n,vector<int>adjList[],unordered_map<int,bool>&visited,int node)
    {
        
        unordered_map<int,int>parent;
        queue<int>q;
        q.push(node);
        visited[node]=1;
        parent[node]=-1; //1 st node won't be having parent node
    
        while(!q.empty())
        {
            int frontNode=q.front();
            q.pop();
    
            for(auto val:adjList[frontNode])
            {
                if(visited[val] && parent[frontNode]!=val )
                {
                    return true;
                }
                else if(!visited[val])
                {
                    q.push(val);
                    visited[val]=1;
                    parent[val]=frontNode;
                }
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
                bool ans=isCycleBFS(n,adj,visited,i);
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