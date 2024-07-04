class Solution {
public:
    string removeOuterParentheses(string s) {
        
        //TC :O(N)
        //SC :O(N)
        //Approach 1
        /*
        string ans="";
        stack<char>st;
        int n=s.length();
        for(int i=0;i<n;i++)
        {
            if (s[i] == '(')
            {
                if(st.empty()==false) ans+="("; //so when the stack is not empty means we have a inner pair of brackets so just put it in the answer 
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
                        if(st.empty()==false) ans+=")";  //Now after popping stack is empty means this was the last bracket so don't put it in the ans
                    }  
                }
            }
        }
        return ans;
        */
        
        //TC :O(N)
        //SC :O(1)
        //Approach 2
        string ans="";
        int n=s.length(),count=0;
        for(int i=0;i<n;i++)
        {
            if(s[i]=='(') count++;
            else count--;
            
            if((count==1 && s[i]=='(') || count==0) continue; //coz the brackets having that count is the outermost brackets
            else ans+=s[i];
        }
        return ans;
    }
};