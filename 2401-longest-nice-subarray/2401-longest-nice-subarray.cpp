class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int left=0,right=0,res=0;
        
        int unionBits=0;
        while(right<nums.size())
        {
            while((nums[right]&unionBits)!=0)
            {
                unionBits^=nums[left];
                left++;
            }
            unionBits=unionBits | nums[right];
            res=max(res,right-left+1);
            right++;
        }
        return res;
    }
};