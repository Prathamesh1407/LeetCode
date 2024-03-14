class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int k) {
        unordered_map<int,int>m;
        m[0]=1;
        int pSum=0,c=0;
        for(int i=0;i<nums.size();i++)
        {
            pSum+=nums[i];
            int remove=pSum-k;
            c+=m[remove];
            m[pSum]++;
        }
        return c;
    }
};