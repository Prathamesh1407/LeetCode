class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        unordered_map<string,int>m;
        int ans=0;
        for(auto val:dominoes)
        {
            m[to_string(min(val[0],val[1]))+to_string(max(val[0],val[1]))]++;
        }

        for(auto val:m)
        {
            ans+=((val.second*(val.second-1))/2);
        }
        return ans;
    }
};