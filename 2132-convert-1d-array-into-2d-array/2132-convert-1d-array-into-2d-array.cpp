class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& org, int m, int n) {
        if(m*n!=org.size()) return {};

        //A1: TC: O(n*m)
        /*
        int size=org.size();
        vector<vector<int>>v(m,vector<int>(n));
        int k=0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                v[i][j]=org[k++];
            }
        }
        return v;
        */

        //A2: whenever we have to map 1D to 2D array use this
        /*
            row=i/col;
            col=i%col;
        */

        vector<vector<int>>v(m,vector<int>(n));
        int size=org.size(),row,col;

        for(int i=0;i<size;i++)
        {
            row=i/n;
            col=i%n;

            v[row][col]=org[i];
        }
        return v;
        
    }
};