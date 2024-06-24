//TC : O(N * 2^N)
//SC : O(N * 2^N)
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n=nums.size();
        int subset=1<<n;
        vector<vector<int>>ans;
        for(int num=0;num<subset;num++)
        {
            vector<int>output;
            for(int j=0;j<n;j++)
            {
                if((num&(1<<j))) output.push_back(nums[j]);
            }
            ans.push_back(output);
        }
        return ans;
    }
};