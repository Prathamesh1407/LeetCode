class Solution {
    bool allZero(vector<int>&v)
    {
        for(auto val:v) if(val!=0) return 0;
        return 1;
    }
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int>v(26,0);
        vector<int>res;

        for(auto val:p) v[val-'a']++;
        int i=0,j=0,ans=0;
        while(j<s.length())
        {
            v[s[j]-'a']--;
            if(j-i+1==p.length())
            {
                if(allZero(v))
                {
                    ans++;
                    res.push_back(i);
                }
                v[s[i]-'a']++;
                i++;
            }
            j++;
        }
        //cout<<ans;
        return res;
        
    }
};