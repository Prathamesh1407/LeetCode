class Solution {

    int solve(vector<int> arr , int target , int s , int e)
    {
        while(s<=e)
        {
            int mid = (s+e)/2;
            if(arr[mid] == target)
            {
                return mid ;
            } 
            else if(arr[mid]<target)
            {
                s=mid+1;
            }
            else e=mid-1;
        }  
        return -1;
    }
    public:
    int search(vector<int>& nums, int target) {
        ios_base::sync_with_stdio(false);
        int s = 0 ;
        int e = nums.size()-1;
        return solve(nums,target,s,e);
    }
};