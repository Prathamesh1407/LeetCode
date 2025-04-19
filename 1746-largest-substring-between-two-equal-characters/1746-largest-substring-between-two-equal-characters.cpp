class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        vector<int>a(26,-1);
        int ans=-1;
        for(int i=0;i<s.length();i++)
        {
            if(a[s[i]-'a']!=-1)
            {
                ans=max(ans,i-a[s[i]-'a']-1);
            }
            else a[s[i]-'a']=i;
        }

        return ans;
    }
};