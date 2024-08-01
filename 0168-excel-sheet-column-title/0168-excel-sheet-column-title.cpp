class Solution {
public:
    string convertToTitle(int n) {
        string ans;
        while(n--)
        {
            ans.push_back('A'+n%26);
            
            n/=26;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};