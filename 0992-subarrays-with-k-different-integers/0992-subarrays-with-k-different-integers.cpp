class Solution {
    int solve(vector<int>nums,int k)
    {
       int left=0, right=0, res=0;
        unordered_map<int, int>m;
        while(right<nums.size())
        {
           m[nums[right]]++;
                while(m.size()>k)
                {
                    m[nums[left]]--;
                    if(m[nums[left]]==0) m.erase (nums[left]);
                    left++;
                }
            res+=left-right+1;
            right++;
        }
        return res;
}
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
    return solve(nums,k-1)-solve(nums,k);
    }
};