//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    void dfs(int node,vector<vector<int>>&adj,vector<int>&visited,stack<int>&st)
    {
        visited[node]=1;
        
        for(auto val:adj[node])
        {
            if(visited[val]==false)
            {
                dfs(val,adj,visited,st);
            }
        }
        st.push(node);
    }
    void dfs2(int node,vector<int>adjT[],vector<int>&visited)
    {
        visited[node]=1;
        
        for(auto val:adjT[node])
        {
            if(visited[val]==false)
            {
                dfs2(val,adjT,visited);
            }
        }
    }
	public:
	//Function to find number of strongly connected components in the graph.
    int kosaraju(int v, vector<vector<int>>& adj)
    {
        //code here
        stack<int>st;
        vector<int>visited(v,0);
        //Find Topological Sort
        for(int i=0;i<v;i++)
        {
            if(visited[i]==false)
            {
                dfs(i,adj,visited,st);
            }
        }
        vector<int>adjT[v];
        //Transpose the Graph Reverse the direction of edges
        for(int i=0;i<v;i++)
        {
            visited[i]=0;
            for(auto val:adj[i])
            {
                adjT[val].push_back(i);
            }
        }
        int scc=0;
        while(!st.empty())
        {
            int frontNode=st.top();
            st.pop();
            
            if(visited[frontNode]==false)
            {
                scc++;
                dfs2(frontNode,adjT,visited);
            }
            
        }
        return scc;
    }
};

//{ Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E;
    	cin >> V >> E;

    	vector<vector<int>> adj(V);

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    	}

    	Solution obj;
    	cout << obj.kosaraju(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends