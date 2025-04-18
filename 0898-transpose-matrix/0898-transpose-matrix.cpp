class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        int n=matrix.size(),m=matrix[0].size();
        vector<vector<int>>mat(m,vector<int>(n));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                mat[j][i]=matrix[i][j];
            }
        }

        return mat;


        // Follow up Q what if input is always square matrix
        /*
            for(int i=0;i<n;i++)
            {
                for(int j=i+1;j<m;j++) //i+1 coz avoiding swapping swapped elements
                {
                    swap(mat[i][j],mat[j][i]);
                }
            }
        */ 
    }
};