class Solution {
    bool bfs(int start,vector<vector<int>>& graph,int color[])
    {
        queue<int>q;
        q.push(start);
        color[start]=0;
        
        while(!q.empty())
        {
            int frontNode=q.front();
            q.pop();
            
            for(auto val:graph[frontNode])
            {
                if(color[val]==-1)
                {
                    color[val]=!color[frontNode];
                    q.push(val);
                }
                else if(color[val]==color[frontNode]) return false;
            }
        }
        return true;
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        int color[n];
        
        for(int i=0;i<n;i++) color[i]=-1;
        
        for(int i=0;i<n;i++)
        {
            if(color[i]==-1)
            {
                if(bfs(i,graph,color)==false) return 0;
            }
        }
        return 1;
    }
};