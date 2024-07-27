class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& org, vector<char>& chng, vector<int>& cost) {
        
        vector<vector<int>>v(26,vector<int>(26,INT_MAX));
        
        for(int i=0;i<org.size();i++)
        {
            v[org[i]-'a'][chng[i]-'a']=min(v[org[i]-'a'][chng[i]-'a'],cost[i]);
        }
        for(int i=0;i<26;i++) v[i][i]=0;
        for(int via=0;via<26;via++)
        {
            for(int i=0;i<26;i++)
            {
                for(int j=0;j<26;j++)
                {
                    if(v[i][via]==INT_MAX || v[via][j]==INT_MAX) continue;
                    v[i][j]=min(v[i][j],v[i][via]+v[via][j]);
                }
            }
        }
        long long ans=0;
        for(int i=0;i<source.length();i++)
        {
            if(v[source[i]-'a'][target[i]-'a']==INT_MAX) return -1;
            ans+=v[source[i]-'a'][target[i]-'a'];
        }
        return ans;
    }
};