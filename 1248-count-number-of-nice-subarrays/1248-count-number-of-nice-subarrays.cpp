//TC : O(2N)
class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int left=0,right=0,res=0,odd=0,prevCount=0;
        
        while(right<nums.size())
        {
            if(nums[right]&1) 
            {
                //Encountered with odd
                odd++;
                prevCount=0;
            }
            while(odd==k)
            {
                prevCount++;
                if(left<nums.size() && (nums[left]&1)) 
                {
                    odd--;
                }
                left++;         
            }
            res+=prevCount;
            right++;
        }
        return res;
    }
};