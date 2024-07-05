class Solution {
public:
    int minAddToMakeValid(string s) {
        //TC :O(N) 
        //SC :O(1)
        /*
        int c=0,ans=0;
        for(auto val:s)
        {
            if(val=='(') c++;
            else c--;
            if(c<0) 
            {
                ans+=abs(c);
                c=0;
            }
        }
        return ans+c;
        */
        
        stack<int>st;
        int n=s.length();
        for(int i=0;i<n;i++)
        {
            if(s[i]=='(')
            {
                st.push(s[i]);
            }
            else
            {
                if(!st.empty())
                {
                    if(st.top()=='(') st.pop();
                    else 
                    {
                        st.push(')');
                    }
                }
                else st.push(')');
            }
        }
        return st.size();
    }
};