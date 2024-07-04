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
        
        /*
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
        */
        
        //nlogn + min(first.length(),last.length())
        if(strs.size()==0) return "";
        sort(strs.begin(),strs.end());
        string first=strs[0];
        string last=strs[strs.size()-1];
        string ans="";
        for(int i=0;i<min(first.length(),last.length());i++)
        {
            if(first[i]!=last[i]) return ans;
            else ans+=first[i];
        }
        return ans;
    }
};