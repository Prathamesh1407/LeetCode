class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        vector<int>ans(nums.size(),0);
        int k=0;

        for(int i=0;i<nums.size()-1;i++)
        {
            if(nums[i]!=0 && nums[i]==nums[i+1])
            {
                ans[k++]=nums[i]*2;
                nums[i+1]=0;
            }
            else if(nums[i]!=0) ans[k++]=nums[i];
        }
        if(nums[nums.size()-1]!=0) ans[k]=nums[nums.size()-1];
        return ans;
    }
};