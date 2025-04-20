class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int i=0,j=nums.size()-1;
        int k=j;
        vector<int>ans(nums.size());
        while(i<=j)
        {
            if(abs(nums[j])>abs(nums[i]))
            {
                ans[k--]=pow(nums[j],2);
                j--;
            }
            else
            {
                ans[k--]=pow(nums[i],2);
                i++;
            }
        }
        return ans;
    }
};