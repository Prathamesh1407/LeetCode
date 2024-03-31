class Solution {
public:
    int lengthOfLastWord(string s) {
        int c=0,i=s.length()-1;
        while(s[i]==' ')
        {
            i--;
        }
        while(i>=0 && s[i]!=' ')
        {
            c++;
            i--;
        }
        return c;
    }
};