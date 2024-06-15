class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        
        queue<pair<pair<int,int>,int>>q;      
        int visited[n][m];
        
        int deltaRow[]={-1,0,1,0};
        int deltaCol[]={0,1,0,-1};
        
        int countFresh=0,countRotten=0;
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==2)
                {
                    q.push({{i,j},0});
                    visited[i][j]=2;
                }
                else 
                {
                    visited[i][j]=0;
                }
                if(grid[i][j]==1) 
                {
                    countFresh++;
                }
            }
        }
        int tm=0;
        while(!q.empty())
        {
            int row=q.front().first.first;
            int col=q.front().first.second;
            int time=q.front().second;
            tm=max(tm,time);
            q.pop();
            for(int i=0;i<4;i++)
            {
                int newRow=row+deltaRow[i];
                int newCol=col+deltaCol[i];
                
                if(newRow >=0 && newCol>=0 && newRow<n && newCol<m && visited[newRow][newCol]!=2 && grid[newRow][newCol]==1)
                {
                    q.push({{newRow,newCol},time+1});
                    visited[newRow][newCol]=2;
                    countRotten++;
                }
            }
            
        }
        
        if(countFresh!=countRotten) return -1;
        return tm;
    }
};