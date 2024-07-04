class Solution {
public:
    string reverseWords(string s) {
        //TC :O(N^2) //becaus at each time we are concatenating the string and as i will increase complexity will increase
        //SC : O(2N)
        /*
        string ans="",temp="";
        int n=s.length();
        for(auto val:s)
        {
            if(val!=' ') temp+=val;
            else if(temp!="")
            {
                ans=temp+" "+ans;
                temp="";
            }
        }
        if(temp!="") ans=temp+" "+ans;
        ans.pop_back();
        return ans;
        */
        
        //TC :O(N*(Avg length of Word))
        //SC : O(1)
        int i=0,l=0,r=0;
        int n=s.length();
        
        reverse(s.begin(),s.end());
        while(i<n)
        {
            while(i<n && s[i]!=' ')
            {
                s[r]=s[i];
                r++;
                i++;
            }
            //Now space comes
            if(l<r)
            {
                reverse(s.begin()+l,s.begin()+r);
                s[r]=' ';
                r++;
                l=r;
            }
            i++;    
        }
        return s.substr(0,r-1);
    }
};