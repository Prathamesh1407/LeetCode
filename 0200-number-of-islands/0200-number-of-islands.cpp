class Solution {
    void bfs(int row,int col,vector<vector<char>>& grid,vector<vector<int>>&visited)
    {
        visited[row][col]=1;
        
        queue<pair<int,int>>q;
        
        q.push({row,col});
        //co-ordinates
        int rowSize=grid.size();
        int colSize=grid[0].size();
        int deltaRow[]={-1,0,1,0};
        int deltaCol[]={0,1,0,-1};
        while(!q.empty())
        {
            pair<int,int>frontNode=q.front();
            int frow=frontNode.first;
            int fcol=frontNode.second;
            q.pop();
            for(int i=0;i<4;i++)
            {
                int newRow=frow+deltaRow[i];
                int newCol=fcol+deltaCol[i];
                
                if(newRow>=0 && newRow<rowSize && newCol>=0 && newCol<colSize && grid[newRow][newCol]=='1' && visited[newRow][newCol]==0 )
                {
                    visited[newRow][newCol]=1;
                    q.push({newRow,newCol});
                }
            }
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int count=0;
        vector<vector<int>>visited(n,vector<int>(m,0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]=='1' && visited[i][j]==0)
                {
                    count++;
                    bfs(i,j,grid,visited);
                }
            }
        }
        return count;
    }
};