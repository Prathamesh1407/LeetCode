class Solution {
public:
    int minAddToMakeValid(string s) {
        int c=0,ans=0;
        for(auto val:s)
        {
            if(val=='(') c++;
            else c--;
            if(c<0) 
            {
                ans+=abs(c);
                c=0;
            }
        }
        return ans+c;
    }
};