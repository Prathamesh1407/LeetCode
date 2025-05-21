class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        vector<int>ans(nums.size(),-1);
        if(k*2 + 1>nums.size()) return ans;
        long long int windowSum=0;
        for(int z=0;z<=2*k;z++)
        {
            windowSum+=nums[z];
        }
        ans[k]=windowSum/(long long)(2*k+1);
        int i=0,j=2*k+1,z=k;
        while(j<nums.size())
        {
            windowSum-=nums[i++];
            windowSum+=nums[j++];
            z=k+i;
            ans[z]=windowSum/(long long)(2*k+1);
        }
        return ans;
    }
};