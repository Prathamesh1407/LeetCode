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
            if(nums[mid]>target)
            {
                if(nums[mid]==target) ans=mid;
                high=mid-1;
            }
            else low=mid+1;
        }
        return ans;
    }
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int lower=-1,upper=-1;
        int start = 0, end =nums.size() - 1;
        while(start <= end) {
            int mid = start + (end-start)/2;
            if(nums[mid] < target) start = mid+1;
            else {
                if(nums[mid] == target) lower = mid;
                end = mid-1;
            }
        }
        start = 0, end =nums.size() - 1;
        while(start <= end) {
            int mid = start + (end-start)/2;
            if(nums[mid] > target) end = mid-1;
            else {
                if(nums[mid] == target) upper= mid;
                start = mid+1;
            }
        }
        return {lower,upper};
    }
};