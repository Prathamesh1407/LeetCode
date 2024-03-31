class Solution {
public:
    int lengthOfLastWord(string s) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
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