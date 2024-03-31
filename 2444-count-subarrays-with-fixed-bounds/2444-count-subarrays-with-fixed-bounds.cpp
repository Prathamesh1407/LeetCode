class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        int left=-1,right=-1,bad=-1,i=0;
        long long res=0;
        while(i<nums.size())
        {
            if(!(nums[i]>=minK && nums[i]<=maxK)) bad=i;
            
            if(nums[i]==minK) left=i;
            if(nums[i]==maxK) right=i;
            res+=max(0,min(left,right)-bad);
            i++;
        }
        return res;
    }
};