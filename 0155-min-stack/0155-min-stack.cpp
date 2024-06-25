class MinStack {
    stack<long long int>st;
    long long int mini=LONG_MAX;
public:
    MinStack() {
        
    }
    
    void push(int value) {
        long long val=value;
        if(st.empty())
        {
            st.push(val);
            mini=val;
        }
        else
        {
            if(val<mini)
            {
                long long modifiedValue=2*val*1LL-mini;
                mini=val;
                st.push(modifiedValue);
            }
            else
            {
                st.push(val);
            }
        }
    }
    
    void pop() {
        if(st.top()<mini)
        {
            //Means it's a modified value so first we have to update mini to previous minimum element
            long long prevMini=2*mini*1LL-st.top(); 
            st.pop();
            mini=prevMini;
        }
        else st.pop();
    }
    
    int top() {
        if(st.top()<mini)
        {
            return mini;
        }
        else
        {
            return st.top();
        }
    }
    
    int getMin() {
        return mini;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */