class Solution {
public:
    int minimumDeletions(string s) {
        
        //TC : O(N)
        //SC : O(N)
        stack<char>st;
        int i=0,ans=0;
        
        for(int i=0;i<s.length();i++)
        {
            if(!st.empty() && s[i]=='a' && st.top()=='b')
            {
                st.pop();
                ans++;
            }
            else st.push(s[i]);
        }
        return ans;
    }
};