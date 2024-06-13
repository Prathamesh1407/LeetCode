//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    void makeSet(vector<int>&parent,vector<int>&rank,int n)
    {
        for(int i=0;i<n;i++)
        {
            parent[i]=i;
            rank[i]=0;
        }
    }
    
    int findParent(vector<int>&parent,int node)
    {
        if(parent[node]==node) return node;
        
        return parent[node]=findParent(parent,parent[node]);
    }
    
    void unionSet(int u,int v,vector<int>&parent,vector<int>&rank)
    {
        u=findParent(parent,u);
        v=findParent(parent,v);
        
        if(rank[u]<rank[v])
        {
            parent[u]=v;
        }
        else if(rank[u]>rank[v])
        {
            parent[v]=u;
        }
        else
        {
            //can make any node parent of other node and upgrade the rank of the parent node
            parent[v]=u;
            rank[u]++;
        }
    }
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int n, vector<vector<int>> adj[])
    {
        // code here
        vector<int>parent(n);
        vector<int>rank(n);
        makeSet(parent,rank,n);
        
        vector<pair<int,pair<int,int>>> edges;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<adj[i].size();j++){
                edges.push_back({adj[i][j][1],{i,adj[i][j][0]}});
            }
        }
        int minCost=0;
        //sort the adjList Acc to weight
        sort(edges.begin(),edges.end());
        for(int i=0;i<edges.size();i++)
        {
            int u=edges[i].second.first;
            int v=edges[i].second.second;
            
            int wt=edges[i].first;
            
            if(findParent(parent,u)!=findParent(parent,v))
            {
                minCost+=wt;
                unionSet(u,v,parent,rank);
            }
        }
        return minCost;
    }
};

//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends