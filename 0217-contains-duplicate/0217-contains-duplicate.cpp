class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        unordered_map<int,int>m;
        for(auto val:nums)
        {
            if(m.find(val)!=m.end()) return 1;
            else m[val]++;
        }
        return 0;
    }
};