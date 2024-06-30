class StockSpanner {
public:
    stack<pair<int,int>>st;
    StockSpanner() {
        
    }
    
    int next(int price) {
        int span=1;
        //If top element is smaller than the current price then the span can be added to it
        while(st.empty()==false && st.top().first<=price)
        {
            span+=st.top().second;
            st.pop();
        }
        
        st.push({price,span});
        return span;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */