class Solution {
    //Space optimization Logic of House Robber 1
    int solve(vector<int>nums,int n)
    {
        int prev2=0,prev=nums[0];
        for(int ind=1;ind<n;ind++)
        {
            int pick=nums[ind];
            if(ind>1) pick+=prev2;
        
            //Not pick
            int notPick=0+prev;

            int curri=max(pick,notPick);
            prev2=prev;
            prev=curri;
        }
        return prev;
    }
public:
    int rob(vector<int>& nums) {
        vector<int>temp1,temp2;
        int n=nums.size();
        if(n==1) return nums[0];
        for(int i=0;i<n;i++)
        {
            if(i!=0) temp1.push_back(nums[i]);
            if(i!=n-1) temp2.push_back(nums[i]);
        }
        return max(solve(temp1,n-1),solve(temp2,n-1));
    }
};