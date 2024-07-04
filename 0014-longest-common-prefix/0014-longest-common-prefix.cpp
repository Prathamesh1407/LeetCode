class Solution {
    string getCommonPart(string s1,string s2)
    {
        int n=min(s1.length(),s2.length());
        string ans="";
        for(int i=0;i<n;i++)
        {
            if(s1[i]!=s2[i]) return ans;
            else ans+=s1[i];
        }
        return ans;
    }
public:
    string longestCommonPrefix(vector<string>& strs) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        /*
        if(strs.size()==0) return "";
        string prefix=strs[0];
        
        for(int i=1;i<strs.size();i++)
        {
            while(strs[i].find(prefix)!=0)
            {
                prefix=prefix.substr(0,prefix.length()-1);
            }
        }
        return prefix;
        */
        if(strs.size()==0) return "";
        string prefix=strs[0];
        
        for(int i=1;i<strs.size();i++)
        {
            prefix=getCommonPart(prefix,strs[i]);
        }
        return prefix;
        
    }
};