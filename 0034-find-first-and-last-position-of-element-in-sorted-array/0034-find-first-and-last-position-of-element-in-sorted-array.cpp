class Solution {
    int lowerBound(vector<int>& nums, int target)
    {
        //Lower Bound
        int low=0,high=nums.size()-1,ans=-1;
        while(low<=high)
        {
            int mid=low+((high-low)/2);
            if(nums[mid]>=target)
            {
                if(nums[mid]==target) ans=mid;
                high=mid-1;
            }
            else low=mid+1;
        }
        return ans;
    }
    int upperBound(vector<int>& nums, int target)
    {
        int low=0,high=nums.size()-1,ans=-1;
        while(low<=high)
        {
            int mid=low+((high-low)/2);
            if(nums[mid]<=target)
            {
                if(nums[mid]==target) ans=mid;
                low=mid+1;
            }
            else high=mid-1;
        }
        return ans;
    }
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int lower=lowerBound(nums,target);
        int upper=upperBound(nums,target);
        return {lower,upper};
    }
};