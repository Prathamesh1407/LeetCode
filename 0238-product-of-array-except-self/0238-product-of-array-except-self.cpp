class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        vector<int>ans(nums.size());
        int premult=1;
        vector<int>pre(nums.size()+1);
        vector<int>post(nums.size()+1);
        pre[0]=1;
        post[nums.size()]=1;
        for(int i=0;i<nums.size();i++)
        {
            pre[i+1]=pre[i]*nums[i];
        }
        for(int i=nums.size()-1;i>=0;i--)
        {
            post[i]=post[i+1]*nums[i];
        }
        for(int i=1;i<=nums.size();i++)
        {
            ans[i-1]=pre[i-1]*post[i];
        }
        return ans;
    }
};