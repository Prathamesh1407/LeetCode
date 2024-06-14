//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
    int timer=0;
    void dfs(int node,int parent,vector<int>&tin,vector<int>&low,vector<int>adj[],vector<int>&points,vector<int>&visited)
    {
        visited[node]=1;
        
        tin[node]=low[node]=timer++;
        int child=0;
        for(auto val:adj[node])
        {
            if(val==parent) continue;
            if(visited[val]==0)
            {
                dfs(val,node,tin,low,adj,points,visited);
                low[node]=min(low[node],low[val]);
                
                //check for articulation point : the adj point should reach before the node and if it doesn't it's a point
                
                if(low[val]>=tin[node] && parent!=-1)
                {
                    points[node]=1;
                }
                child++;
            }
            else
            {
                low[node]=min(low[node],tin[val]);
            }
        }
	//This condition is for parent if parent having more than 1 child then it is an articulation point
        if(child>1 && parent==-1) points[node]=1;
    }
  public:
    vector<int> articulationPoints(int v, vector<int>adj[]) {
        // Code here
        vector<int>tin(v);
        vector<int>low(v);
        vector<int>visited(v,0);
        
        vector<int>points(v,0);
        vector<int>ans;
        
        dfs(0,-1,tin,low,adj,points,visited);
        for(int i=0;i<v;i++)
        {
            if(points[i]==1) ans.push_back(i);
        }
        if(ans.size()==0) return {-1};
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		vector<int> ans = obj.articulationPoints(V, adj);
		for(auto i: ans)cout << i << " ";
		cout << "\n";
	}
	return 0;
}
// } Driver Code Ends
