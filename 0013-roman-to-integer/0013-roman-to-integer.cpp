class Solution {
    int pri(char c)
    {
        if(c=='I') return 1;
        if(c=='V') return 5;
        if(c=='X') return 10;
        if(c=='L') return 50;
        if(c=='C') return 100;
        if(c=='D') return 500;
        else return 1000;

    }
    
public:
    int romanToInt(string s) {
        int ans=0,n=s.length();
        if(n==1) return pri(s[0]);
        ans=pri(s[n-1]);
        for(int i=n-2;i>=0;i--)
        {
            if(pri(s[i])<pri(s[i+1])){
                ans-=pri(s[i]);
            } 
            else
            {
                ans+=pri(s[i]);
            }
        }
        return ans;   
    }
};