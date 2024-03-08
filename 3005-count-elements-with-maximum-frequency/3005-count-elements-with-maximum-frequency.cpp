class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int,int>m;
        int maxCount=INT_MIN;
        for(int i=0;i<nums.size();i++)
        {
            m[nums[i]]++;
            maxCount=max(maxCount,m[nums[i]]);
        }
        int ans=0;
        for(auto val:m)
        {
            if(val.second==maxCount) ans+=maxCount;
        }
        return ans;
    }
};