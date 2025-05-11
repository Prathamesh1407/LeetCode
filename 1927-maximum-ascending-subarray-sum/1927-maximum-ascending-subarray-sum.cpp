class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int left=0,right=0,maxi=-1,n=nums.size();
        int prev=0,sum=0;
        while(left<n && right<n)
        {
            if(nums[right]>prev)
            {
                sum+=nums[right];
                maxi=max(maxi,sum);
                prev=nums[right];
                right++;
            }
            else
            {
                sum=0;
                prev=0;
                left=right;
            }
        }
        return maxi;
    }
};