class Solution {
    void solve(vector<int>& nums,int ind,vector<vector<int>>&subset,vector<int>&currSub)
    {
        if(ind==nums.size()) 
        {
            subset.push_back(currSub);
            return;
        }

        //Pick
        currSub.push_back(nums[ind]);
        solve(nums,ind+1,subset,currSub);
        //Not Pick

        currSub.pop_back();
        solve(nums,ind+1,subset,currSub);
    }
public:
    int subsetXORSum(vector<int>& nums) {
        //A1: Generate all the subset and add them TC: O(2^n * Avg L of subset)

        vector<vector<int>>subset;
        vector<int>currSub;
        solve(nums,0,subset,currSub);
        int ans=0;
        for(auto &val:subset)
        {
            int XOR=0;
            for(auto &num:val)
            {
                XOR^=num;
            }
            ans+=XOR;
        }
        return ans;
    }
};