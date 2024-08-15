class MyCalendar {
public:
    set<pair<int,int>>s;
    MyCalendar() {
    }
    
    bool book(int start, int end) {
        if(s.size()==0) 
        {
            s.insert({start,end});
            return 1;
        }
        
        for(auto val:s)
        {
            if((val.first<=start && val.second>start) || (start<=val.first && end>val.first)) 
            {
                return 0; 
            }
        }
        s.insert({start,end});
        return 1;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */