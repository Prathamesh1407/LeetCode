class Solution {
public:
    vector<int> asteroidCollision(vector<int>& ast) {
        stack<int>st;
        int n=ast.size();
        
        for(int i=0;i<n;i++)
        {
            if(st.empty()==true || ast[i]>0) st.push(ast[i]);
            else
            {
                while(st.empty()==false && st.top()>0 && st.top()<abs(ast[i]))
                {
                    st.pop();
                }
                if(st.empty()==false && abs(ast[i])==st.top()) st.pop();
                else if(st.empty()==true || st.top()<0 ) st.push(ast[i]);
            }
        }
        n=st.size();
        int i=0;
        vector<int>ans(n);
        while(st.empty()==false)
        {
            ans[n-i-1]=st.top();
            st.pop();
            i++;
        }
        return ans;
    }
};