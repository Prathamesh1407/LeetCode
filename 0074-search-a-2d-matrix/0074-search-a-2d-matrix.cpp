class Solution {
public:
    bool searchMatrix(vector<vector<int>>& a, int key) {
        
        //TC : O(N + log2(M))
        
        //A1: every row is sorted so check the 1st and last element of each row by comparing target and if satisfies apply binary search on that row
        
        
        //TC : O(log2(N*M))
        int row=a.size(),col=a[0].size();
        int s=0,e=row*col-1,mid;
        while(s<=e)
        {
            mid=s+(e-s)/2;
            int rowInd=mid/col,colInd=mid%col;
            int element=a[rowInd][colInd];
            if(element==key) 
            {
                return 1;
            }
            if(element>key) e=mid-1;
            else s=mid+1;
        }
        return 0;
    }
};
