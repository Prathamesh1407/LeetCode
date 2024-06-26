class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        unordered_map<int,int>m;
        vector<int>v;
        for(int i=0;i<nums.size();i++)
        {
            if(m.find(target-nums[i])!=m.end()) 
            {
                v.push_back(i);
                v.push_back(m[target-nums[i]]);
                break;
            }
            else m[nums[i]]=i;
        }
        return v;
    }
};