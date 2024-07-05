class Solution {
public:
    int countHomogenous(string s) {
        int n=s.length();
        int ans=0,left=0,right=0,i=0;
        int mod=1e9+7;
        while(right<n)
        {
            if(s[left]==s[right])
            {
                ans=(ans+right-left+1)%mod;
            }
            else
            {
                left=right;
                ans+=1;
            }
            right++;
        }
        return (ans%mod);
    }
};