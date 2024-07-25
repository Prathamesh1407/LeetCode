class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        //A1: 
        //TC : O(2N)
        int left=0,right=0,zeros=0,res=0,ind=-1;
        
        while(right<nums.size())
        {
            if(nums[right]!=1)
            {
                zeros++;
            }
            while(zeros>k)
            {
                if(nums[left]==0) zeros--;
                left++;
            }
            if(zeros>=0) res=max(res,right-left+1);
            right++;
        }
        return res;
    }
};