class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>>m;
        vector<vector<string>>ans;
        for(auto val:strs)
        {
            string s=val;
            sort(s.begin(),s.end());
            m[s].push_back(val);
            
        }
        for(auto val:m)
        {
            ans.push_back(val.second);
        }
        return ans;
    }
};