class Solution {
    int findLocalMax(vector<vector<int>>& grid,int x,int y)
    {
        int maxi=0;
        for(int i=x;i<=x+2;i++)
        {
            for(int j=y;j<=y+2;j++)
            {
                maxi=max(grid[i][j],maxi);
            }
        }
        return maxi;
    }
public:
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        int row=grid.size(),col=grid[0].size();
        vector<vector<int>>ans(row-2,vector<int>(row-2));
        for(int i=0;i<row-2;i++)
        {
            for(int j=0;j<col-2;j++)
            {
                ans[i][j]=findLocalMax(grid,i,j);
            }
        }
        return ans;
    }
};