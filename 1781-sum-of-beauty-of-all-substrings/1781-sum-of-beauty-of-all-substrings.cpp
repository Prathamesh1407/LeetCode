class Solution {
public:
    int beautySum(string s) {
        int ans=0,n=s.length();
        for(int i=0;i<n;i++)
        {
            vector<int>v(26,0);
            
            for(int j=i;j<n;j++)
            { 
                int mini=INT_MAX,maxi=0;
                v[s[j]-'a']++;
                for(int k=0;k<26;k++)
                {
                    if(v[k]!=0)
                    {
                         mini=min(mini,v[k]);
                         maxi=max(maxi,v[k]);   
                    }
                }
                ans+=(maxi-mini);
            }
        }
        return ans;
    }
};