//TC : O(N + M) if the target is in opposite corner whole n + m have to be traversed
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        //Now if we start from the 1st element the right and down part is in ascending order so we can't be able to find the element, so we will take the last element of 1st row the left part is descending and down part is ascending we can find the element and same goes for last element of 1st column
        int n=matrix.size(),m=matrix[0].size();
        int row=0,col=m-1;
        while(row<n && col>=0)
        {
            if(matrix[row][col]==target)
            {
                return 1;
            }
            else if(matrix[row][col]<target)
            {
                row++;
            }
            else col--;
        }
        return 0;
    }
};