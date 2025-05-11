class Solution {
public:
    string clearDigits(string s) {
        stack<char>st;

        for(auto val:s)
        {
            if(!isdigit(val))
            {
                st.push(val);
            }
            else
            {
                if(st.empty()) st.push(val);
                else
                {
                    if(!isdigit(st.top())) st.pop();
                }
            }
        }
        string ans;
        while(!st.empty()) 
        {
            ans.push_back(st.top());
            st.pop();
        }

        reverse(ans.begin(),ans.end());
        return ans;
    }
};