class Solution {
    bool isPalindrome(int i,int j,string & s)
    {
        if(i>=j)
        {
            return true;
        }
        if(s[i]==s[j]) return isPalindrome(i+1,j-1,s);
        return false;
    }
public:
    string longestPalindrome(string s) {
        int n=s.length();
        int maxlen=0,sp;
        for(int i=0;i<n;i++)
        {
            for(int j=i+maxlen;j<n;j++)
            {
                if(isPalindrome(i,j,s))
                {
                    if(j-i+1>maxlen)
                    {
                        maxlen=j-i+1;
                        sp=i;
                    }
                }
            }
        }
        return s.substr(sp,maxlen);
    }
};