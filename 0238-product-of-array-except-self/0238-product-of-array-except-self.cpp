class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        vector<int>ans(nums.size());
        ans[0]=1;
        int n=nums.size();
        for(int i=0;i<n-1;i++)
        {
            ans[i+1]=ans[i]*nums[i];
        }
        int post=nums[n-1];
        for(int i=n-2;i>=0;i--)
        {
            ans[i]=ans[i]*post;
            post*=nums[i];
        }
        return ans;
    }
};