class Solution {
public:
    bool isSubsequence(string s, string t) {
        int c=0;
        for(auto val:t)
        {
            if(val==s[c]) c++;
        }
        return c==s.length();
    }
};