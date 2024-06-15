class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        
        queue<pair<pair<int,int>,int>>q;      
        vector<vector<int>>dist(n,vector<int>(m,0));
        vector<vector<int>>visited(n,vector<int>(m,0));
        
        int deltaRow[]={-1,0,1,0};
        int deltaCol[]={0,1,0,-1};
                
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==0)
                {
                    q.push({{i,j},0});
                    visited[i][j]=1;
                }
            }
        }
        while(!q.empty())
        {
            int row=q.front().first.first;
            int col=q.front().first.second;
            int steps=q.front().second;
            q.pop();
            
            dist[row][col]=steps;
            
            for(int i=0;i<4;i++)
            {
                int newRow=row+deltaRow[i];
                int newCol=col+deltaCol[i];
                
                if(newRow >=0 && newCol>=0 && newRow<n && newCol<m && visited[newRow][newCol]==0)
                {
                    q.push({{newRow,newCol},steps+1});
                    visited[newRow][newCol]=1;
                }
            }
            
        }
        return dist;
    }
};