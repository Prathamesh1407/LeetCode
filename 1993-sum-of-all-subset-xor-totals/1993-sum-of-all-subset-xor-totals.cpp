class Solution {

    int solve2(vector<int>&nums,int ind,int XOR)
    {
        if(ind==nums.size()) 
        {
            return XOR;
        }
        //Pick
        int include=solve2(nums,ind+1,XOR^nums[ind]);

        //Not Pick
        int exclude=solve2(nums,ind+1,XOR);

        return include+exclude;
    }


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
        /*
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
        */

        //A2: Why to store the subsets,direct calculate the xor while recursion TC: O(2^n)

        return solve2(nums,0,0);
    }
};