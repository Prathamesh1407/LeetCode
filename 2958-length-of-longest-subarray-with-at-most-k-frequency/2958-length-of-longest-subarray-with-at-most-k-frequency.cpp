class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int left=0,right=0,result=0;
        unordered_map<int,int>m;
        int maxi=0;
        while(right<nums.size())
        {
            auto it=m.find(nums[right]);
            if((it!=m.end() && it->second<k) || it==m.end() )
            {
                result=right-left+1;
                m[nums[right]]++;
            }
            else 
            {
                while(nums[right]!=nums[left])
                {
                    m[nums[left]]--;
                    left++;
                }
                left++;
            }
            right++;
            maxi=max(result,maxi);
        }
        return maxi;
    }
};