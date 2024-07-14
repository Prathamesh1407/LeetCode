class Solution {
public:
    int findMin(vector<int>& nums) {
        int low=0,high=nums.size()-1,mid,ans=INT_MAX;
        if(nums.size()==1) return nums[0];
        while(low<=high)
        {
            mid=low+(high-low)/2;
            if(nums[low]==nums[mid] && nums[mid]==nums[high])
            {
                ans=min(ans,nums[mid]);
                low++;
                high--;
                continue;
            }
            //Left Sorted
            if(nums[mid]>=nums[low])
            {
                //If left portion is sorted take the minimum as low and then move to the right part
                ans=min(ans,nums[low]);
                low=mid+1;
            }
            else
            {
                //If right portion is sorted take the minimum as mid and then move to the left part
                ans=min(ans,nums[mid]);
                high=mid-1;
            }
        }
        return ans;
    }
};