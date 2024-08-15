class MyCalendarTwo {
public:
    map<int,int>m;
    MyCalendarTwo() {
        
    }
    
    bool book(int start, int end) {
        m[start]++;
        m[end]--;
        int overlap=0;
        for(auto val:m)
        {
            overlap+=val.second;
            if(overlap==3)
            {
                m[start]--;
                m[end]++;
                return 0;
            }
            
        }
        return 1;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */