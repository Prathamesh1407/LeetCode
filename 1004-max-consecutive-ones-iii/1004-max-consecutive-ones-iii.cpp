class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        //A1: 
        //TC : O(2N)
        /*
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
        */
        
        //TC : O(N)
        //We have to get rid of that while loop so instead of going to left till we find zero just move to the left and if 0 zeroes -- and if zeroes<=k only then update the result
        
        int left=0,right=0,zeros=0,res=0,ind=-1;
        
        while(right<nums.size())
        {
            if(nums[right]!=1)
            {
                zeros++;
            }
            if(zeros>k)
            {
                if(nums[left]==0) zeros--;
                left++;
            }
            if(zeros<=k) res=max(res,right-left+1);
            right++;
        }
        return res;
    }
};