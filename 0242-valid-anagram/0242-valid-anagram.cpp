class Solution {
public:
    bool isAnagram(string s, string t) {
        //A1 : Sort the 2 string and if any char differs return false TC : O(nlogn)
        
        //TC:O(n) SC : O(1)
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