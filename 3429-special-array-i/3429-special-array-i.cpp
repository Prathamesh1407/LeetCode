class Solution {
public:
    bool isArraySpecial(vector<int>& nums) {
        if(nums.size()==1) return 1;

        for(int i=1;i<nums.size();i++)
        {
            if(nums[i]%2==nums[i-1]%2) return 0;
        }
        return 1;
    }
};