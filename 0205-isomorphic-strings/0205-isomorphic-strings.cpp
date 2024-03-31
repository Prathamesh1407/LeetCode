class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char,char>m,p;
        int i=0;
        while(i<s.length())
        {
            if((m.find(s[i])!=m.end() && m[s[i]]!=t[i] ) || (p.find(t[i])!=p.end() && p[t[i]]!=s[i]))
            {
                return 0;
            }
            m[s[i]]=t[i];
            p[t[i]]=s[i];
            i++;
        }
        return 1;
    }
};