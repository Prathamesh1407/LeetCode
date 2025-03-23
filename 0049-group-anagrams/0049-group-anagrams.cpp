class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>>m;

        for(auto val:strs)
        {
            vector<int>freq(26,0);
            for(auto ch:val)
            {
                freq[ch-'a']++;
            }
            string temp="";
            for(int i=0;i<26;i++)
            {
                if(freq[i]!=0)
                {
                    temp+=string(freq[i],i+'a');
                }
            }

            m[temp].push_back(val);
    }

    vector<vector<string>> ans;

    for(auto val:m)
    {
        ans.push_back(val.second);
    }
    return ans;
    }
};