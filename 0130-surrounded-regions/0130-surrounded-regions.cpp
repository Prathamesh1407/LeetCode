class Solution {
    void dfs(int row,int col,vector<vector<char>>& board,vector<vector<int>>&visited)
    {
        visited[row][col]=1;
        int deltaRow[]={-1,0,1,0};
        int deltaCol[]={0,1,0,-1};
        int n=board.size();
        int m=board[0].size();
        for(int i=0;i<4;i++)
        {
            int nrow=row+deltaRow[i];
            int ncol=col+deltaCol[i];
            
            if(nrow<n && ncol<m && nrow>=0 && ncol>=0 && visited[nrow][ncol]==0 && board[nrow][ncol]=='O')
            {
                dfs(nrow,ncol,board,visited);
            }
        }
    }
public:
    void solve(vector<vector<char>>& board) {
        int n=board.size();
        int m=board[0].size();
        vector<vector<int>>visited(n,vector<int>(m,0));
        for(int i=0;i<m;i++)
        {
            //for 1st row
            if(board[0][i]=='O' && visited[0][i]==0)
            {
                dfs(0,i,board,visited);
            }
            //for n-1 th row
            if(board[n-1][i]=='O'&& visited[n-1][i]==0)
            {
                dfs(n-1,i,board,visited);
            }
        }
        for(int i=0;i<n;i++)
        {
            //for 0th col
            if(board[i][0]=='O'&& visited[i][0]==0)
            {
                dfs(i,0,board,visited);
            }
            //for n-1 th row
            if(board[i][m-1]=='O'&& visited[i][m-1]==0)
            {
                dfs(i,m-1,board,visited);
            }
        }
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(visited[i][j]==0 && board[i][j]=='O')
                {
                    board[i][j]='X';
                }
            }
        }
    }
};