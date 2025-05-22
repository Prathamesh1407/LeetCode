class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int zeros=0,maxi=0,streak=0;
        int i=0;
        for(int j=0;j<nums.size();j++)
        {
            if(nums[j]==0) zeros++;
            while(zeros>1)
            {
                if(nums[i]==0) zeros--;
                i++;
            }
            maxi=max(maxi,j-i);
        }
        return maxi;
    }
};