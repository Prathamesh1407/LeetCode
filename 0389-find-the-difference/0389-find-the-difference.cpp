class Solution {
public:
    char findTheDifference(string s, string t) {
        int XOR=0;
        for(int i=0;i<s.length();i++)
        {
            XOR^=(int)s[i]^(int)t[i];
        }
        XOR^=(int)t[t.length()-1];
        return (char)XOR;
    }
};