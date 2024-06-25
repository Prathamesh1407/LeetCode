class MyQueue {
public:
    stack<int>ip,op;
    MyQueue() {
        
    }
    
    void push(int x) {
        ip.push(x);
    }
    
    int pop() {
        if(op.empty()==false)
        {
            int x=op.top();
            op.pop();
            return x;
        }
        else
        {
            while(ip.empty()==false)
            {
                op.push(ip.top());
                ip.pop();
            }
            int x=op.top();
            op.pop();
            return x;
        }
    }
    
    int peek() {
        if(op.empty()==false)
        {
            return op.top();
        }
        else
        {
            while(ip.empty()==false)
            {
                op.push(ip.top());
                ip.pop();
            }
            return op.top();
        }
    }
    
    bool empty() {
        return op.empty()&&ip.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */