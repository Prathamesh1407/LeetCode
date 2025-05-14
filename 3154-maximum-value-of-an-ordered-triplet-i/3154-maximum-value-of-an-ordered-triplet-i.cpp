class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        long long maxDiff=0;
        long long maxi=0;
        long long ans=0;
        for(int i=0;i<nums.size();i++)
        {
            ans=max(ans,maxDiff*nums[i]);
            maxDiff=max(maxDiff,maxi-nums[i]);

            maxi=max(maxi,(long long)nums[i]);

        }
        return ans;
    }
};