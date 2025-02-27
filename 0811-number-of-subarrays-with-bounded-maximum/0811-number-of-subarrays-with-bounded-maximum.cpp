class Solution {
public:
    int numSubarrayBoundedMax(vector<int>& nums, int left, int right) {
        int start=-1,end=-1,ans=0;

        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]>right)
            {
                start=end=i;
                continue;
            }
            
            if(nums[i]>=left) end=i;

            ans+=end-start;
        }
        return ans;
    }
};