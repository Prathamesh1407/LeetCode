class Solution {
    int timer =1;
    
    void dfs(int node,int parent,vector<int>&tin,vector<int>&low,vector<int>&visited,unordered_map<int,list<int>>&adjList,vector<vector<int>>&bridges)
    {
        visited[node]=1;
        low[node]=tin[node]=timer++;
        
        for(auto val:adjList[node])
        {
            if(val==parent) continue;
            
            if(visited[val]==0)
            {
                //Not Visited
                
                dfs(val,node,tin,low,visited,adjList,bridges);
                low[node]=min(low[node],low[val]);
                
                //Check the bridge
                if(low[val]>tin[node])
                {
                    bridges.push_back({val,node});
                }
            }
            else
            {
                low[node]=min(low[node],low[val]);
            }
        }
    }
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
    ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        unordered_map<int,list<int>>adjList;
        
        for(auto val:connections)
        {
            adjList[val[0]].push_back(val[1]);
            adjList[val[1]].push_back(val[0]);
        }
        
        vector<int>tin(n);
        vector<int>visited(n,false);
        vector<int>low(n);
        vector<vector<int>>bridges;
        dfs(0,-1,tin,low,visited,adjList,bridges);
        return bridges;
    }
};