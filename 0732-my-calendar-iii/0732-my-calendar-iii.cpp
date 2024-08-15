class MyCalendarThree {
public:
    map<int,int>m;
    int maxCnt=0;
    MyCalendarThree() {
        
    }
    
    int book(int start, int end) {
        m[start]++;
        m[end]--;
        int overlap = 0;
        for (auto val:m) 
        {
            overlap += val.second;
            maxCnt = max(overlap, maxCnt);
        }
        return maxCnt;   
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(startTime,endTime);
 */