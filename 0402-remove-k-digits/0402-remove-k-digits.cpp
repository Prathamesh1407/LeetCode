class Solution {
public:
    string removeKdigits(string num, int k) {
        string ans="";
        int n=num.length(),i=0;
        if(k==n) return "0";
        for(int i=0;i<n;i++)
        {    
            while(ans.length()>0 && ans.back()>num[i] && k>0)
            {
                k--;
                ans.pop_back();
            }
            if(ans.length()>0 || num[i]!=0) ans+=num[i];
        }
        while(k>0)
        {
            k--;
            ans.pop_back();
        }
        i=0;
        while(ans.size()>1 && i<ans.size()-1 && ans[i]=='0')
        {
            i++;
        }
        if(ans=="") return "0";
        return i>0 ? ans.substr(i):ans;
    }
};