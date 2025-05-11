class Solution {
public:
    bool divideArray(vector<int>& nums) {
        unordered_map<int,int>m;
        for(auto val:nums) m[val]++;

        for(auto val:m) if(val.second%2==1) return 0;
        return 1;
    }
};