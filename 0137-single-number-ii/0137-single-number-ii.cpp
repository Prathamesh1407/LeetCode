class Solution {
public:
    int singleNumber(vector<int>& nums) {
        // if every number is appearing for 3 times number of zeroes or ones for that bit will be the %3=0 for all the digits except one so that will be the 1 or 0 for that bit
        int ans=0;
        for(int bit=0;bit<32;bit++)
        {
            int zeros=0,ones=0;
            for(int i=0;i<nums.size();i++)
            {
                int mask=(1<<bit);
                if((mask&nums[i])==0)
                {
                    //bit is 0
                    zeros++;
                }
                else ones++;
            }
            if(ones%3==1) 
            {
                int mask2=(1<<bit);
                ans|=mask2;
            }
        }
        return ans;
    }
};