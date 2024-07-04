class Solution {
public:
    string reverseWords(string s) {
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
    }
};