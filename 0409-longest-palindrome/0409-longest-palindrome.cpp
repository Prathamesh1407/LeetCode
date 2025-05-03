class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char,int>m;
        int ans=0;
        for(auto val:s)
        {
            m[val]++;
        }
        int flag=0;
        for(auto val:m)
        {
            if(val.second%2==0) 
            {
                ans+=val.second;
            }
            else
            {
                //cout<<(v[i]/2)*2<<" ";
                ans+=(val.second/2)*2;
                flag=1; 
            }
        }
        return flag==1? ans+1:ans;
    }
};