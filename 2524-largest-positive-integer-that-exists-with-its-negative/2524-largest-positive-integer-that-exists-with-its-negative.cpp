class Solution {
public:
    int findMaxK(vector<int>& nums) {
        unordered_map<int,int>m;
        int maxi=INT_MIN;
        for(auto val:nums)
        {
            m[val]++;

            if(m.find(val*-1)!=m.end())
            {
                maxi=max(abs(val),maxi);
            }
        }
        return maxi==INT_MIN?-1:maxi;
    }
};