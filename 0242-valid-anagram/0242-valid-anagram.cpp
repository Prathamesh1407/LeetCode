class Solution {
public:
    bool isAnagram(string s, string t) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        vector<int>v(26,0);
        
        for(auto val:s)
        {
            v[val-'a']++;
        }
        for(auto val:t)
        {
            v[val-'a']--;
        }
        for(auto val:v) if(val!=0) return 0;
        return 1;
    }
};