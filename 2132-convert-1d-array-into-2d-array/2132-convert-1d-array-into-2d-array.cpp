class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& org, int m, int n) {
        if(m*n!=org.size()) return {};
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
        
    }
};