class Solution {
public:
    int buyChoco(vector<int>& nums, int money) {
        int smin=INT_MAX,mini=INT_MAX;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]<mini)
            {
                smin=mini;
                mini=nums[i];
            }
            else
            {
                smin=min(smin,nums[i]);
            }
        }

        return smin+mini>money?money:money-(smin+mini);
    }
};