class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        //A1:O(2n)
        /*
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
        */

        //What we were doing in last approach, traversing the i th pointer till next 0 so we will store the last 0 index and will directly jump to it

        int zeros=0,maxi=0,streak=0,lastZeroInd=-1;
        int i=0;
        for(int j=0;j<nums.size();j++)
        {
            if(nums[j]==0) 
            {
                //if j encounters with 0 bring the ith pointer to the next of last 0 
                i=lastZeroInd+1;
                lastZeroInd=j;
            }
            maxi=max(maxi,j-i);
        }
        return maxi;
    }
};