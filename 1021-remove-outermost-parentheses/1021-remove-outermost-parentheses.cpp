class Solution {
public:
    string removeOuterParentheses(string s) {
        string ans="";
        
        stack<char>st;
        int n=s.length();
        for(int i=0;i<n;i++)
        {
            if (s[i] == '(')
            {
                if(st.empty()==false) ans+="(";
                st.push(s[i]);
            }
            else
            {
                if(st.empty()==false)
                {
                    char ch = st.top();
                    if (ch == '(' && s[i] == ')')
                    {
                        st.pop();
                        if(st.empty()==false) ans+=")";  
                    }  
                }
            }
        }
        return ans;
    }
};