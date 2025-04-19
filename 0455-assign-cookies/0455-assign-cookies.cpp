class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        
        //We have to approach greedily if g[i]>=s[i] ans++
        
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        
        int l=0,r=0,ans=0;
        while(l<g.size() && r<s.size())
        {
            if(g[l]<=s[r])
            {
                //Means the child will get Cookie
                ans++;
                l++;
            }
            r++;
        }
        return ans;
    }
};