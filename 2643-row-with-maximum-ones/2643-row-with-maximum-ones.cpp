class Solution {
    int lowerBound(vector<int>&mat,int m)
    {
        int low=0,high=m-1;
        int x=1,ans=-1;
        while(low<=high)
        {
            int mid=(low+high)/2;
            
            if(mat[mid]>=x)
            {
                ans=mid;
                high=mid-1;
            }
            else low=mid+1;
        }
        
        return ans;
    }
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        //If rows is sorted
        int maxRowsOnesCount=0,index=0;
        
        int n=mat.size(),m=mat[0].size();
        for(int i=0;i<n;i++)
        {
            sort(mat[i].begin(),mat[i].end());
            int firstOccurIndOfOne=lowerBound(mat[i],m);
            
            if(firstOccurIndOfOne==-1) continue;
            int NoOfOnes=m-firstOccurIndOfOne;
            
            if(NoOfOnes>maxRowsOnesCount)
            {
                maxRowsOnesCount=NoOfOnes;
                index=i;
            }
        }
        return {index,maxRowsOnesCount};
    }
};