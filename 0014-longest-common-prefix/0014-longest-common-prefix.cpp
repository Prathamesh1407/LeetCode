class Solution {
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
            int n=min(prefix.length(),strs[i].length());
            string ans="";
            for(int j=0;j<n;j++)
            {
                if(prefix[j]!=strs[i][j]) break;
                else ans+=prefix[j];
            }
            prefix=ans;
            if(prefix=="") return prefix;
        }
        return prefix;
    }
};