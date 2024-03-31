class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int left=0,right=0;
        unordered_map<int,int>m;
        while(right<nums.size())
        {
            
            if(right-left>k)
            {
                m.erase(nums[left]);
                left++;
            }
            if(m.find(nums[right])!=m.end()) return true;
            m[nums[right]]++;
            right++;
        }
        return 0;
    }
};