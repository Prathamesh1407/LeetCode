class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int one=0,zero;
        for(auto val:s)
        {
            if(val=='1') one++;
        }
        zero=s.length()-one;
        int i,k=0;
        for(i=0;i<one-1;i++)
        {
            s[k++]='1';
        }
        for(i=0;i<zero;i++)
        {
            s[k++]='0';
        }
        s[s.length()-1]='1';
        return s;
    }
};