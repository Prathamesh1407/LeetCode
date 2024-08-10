//TC : O(n*m*18)
//SC : O(1)

class Solution {
    bool isMagicGrid(vector<vector<int>>& grid,int r,int c)
    {
        unordered_set<int>s;
        for(int i=0;i<3;i++)
        {
            for(int j=0;j<3;j++)
            {
                //Check if all 1 to 9 is present in the matrix or not
                int num=grid[r+i][c+j];
                if(num<1 || num>9 || s.find(num)!=s.end()) return 0;
                else s.insert(num);                
            }
        }
        
        //Check if row col sum matches or not
        int rSum=grid[r][c]+grid[r][c+1]+grid[r][c+2];
        for(int i=0;i<3;i++)
        {
            //Every Row
            if(grid[r+i][c]+grid[r+i][c+1]+grid[r+i][c+2]!=rSum) return 0;
            
            //Every Col
            if(grid[r][c+i]+grid[r+1][c+i]+grid[r+2][c+i]!=rSum) return 0;
        }
        
        //Check if diagonal sum matches or not
        
        //Top -> Bottom Right -> Left
        if(grid[r][c+2]+grid[r+1][c+1]+grid[r+2][c]!=rSum) return 0;
        
        //Top -> Bottom Left -> Right
        if(grid[r][c]+grid[r+1][c+1]+grid[r+2][c+2]!=rSum) return 0;
        
        return 1;
    }
public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size(),c=0;
        
        for(int i=0;i<=n-3;i++)
        {
            for(int j=0;j<=m-3;j++)
            {
                if(isMagicGrid(grid,i,j))
                {
                    c++;
                }
            }
        }
        return c;
    }
};