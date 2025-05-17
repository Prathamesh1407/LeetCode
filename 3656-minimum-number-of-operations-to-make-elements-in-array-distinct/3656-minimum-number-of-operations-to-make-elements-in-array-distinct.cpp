class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        vector<int>v(101,-1);

        for(int i=nums.size()-1;i>=0;i--)
        {
            if(v[nums[i]]!=-1)
            {
                return ceil((i+1)/3.0);
            }
            else v[nums[i]]=i;
        }
        return 0;
    }
};