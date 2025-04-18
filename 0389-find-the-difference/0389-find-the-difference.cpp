class Solution {
public:
    char findTheDifference(string s, string t) {
        int XOR=0;
        for(int i=0;i<s.length();i++)
        {
            XOR^=s[i];
            XOR^=t[i];
        }
        XOR^=t[t.length()-1];
        return (char)XOR;
    }
};