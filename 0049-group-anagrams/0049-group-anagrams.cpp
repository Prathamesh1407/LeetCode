class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        
        //TC : O(N * KlogK) K = Avg length Word
        //SC : O(N)
        /*
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
        */
        
        
        //TC : O(N*K)
        
        
        unordered_map<string,vector<string>>m;
        for(auto val:strs)
        {
            vector<int>v(26,0);
            for(auto ch:val)
            {
                v[ch-'a']++;
            }
            string s;
            for(int i=0;i<26;i++)
            {
                if(v[i]!=0)
                {
                    s+=string(v[i],97+i);
                }
            }
            m[s].push_back(val);
        }
        vector<vector<string>>ans;
        for(auto val:m)
        {
            ans.push_back(val.second);
        }
        return ans;
    }
};
