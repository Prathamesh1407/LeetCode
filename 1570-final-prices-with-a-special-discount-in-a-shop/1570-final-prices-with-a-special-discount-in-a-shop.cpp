class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        stack<int>st;
        vector<int>ans(begin(prices),end(prices));
        int i=0,n=prices.size();
        while(i<n)
        {
            if(st.empty()) st.push(i);
            else
            {
                while(!st.empty() && prices[i]<=prices[st.top()])
                {
                    ans[st.top()]-=prices[i];
                    st.pop();
                }
                st.push(i);
            }
            i++;
        }
        return ans;
    }
};