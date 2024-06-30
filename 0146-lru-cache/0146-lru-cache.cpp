class LRUCache {
public:
    list<int>dll;
    unordered_map<int,pair<list<int>::iterator,int>>mp;
    int cap;
    LRUCache(int capacity) {
        cap=capacity;
    }
    void makeMostFrequent(int key)
    {
        dll.erase(mp[key].first); // Delete with the help of iterator
        dll.push_front(key); // push it on the front as it is frequent one
        
        mp[key].first=dll.begin(); // As now the address is changed
    }
    int get(int key) {
        if(mp.find(key)!=mp.end())
        {
            //Key is Found so make it most frequent and return the value
            makeMostFrequent(key);
            return mp[key].second;
        }
        return -1; //Not Found
    }
    
    void put(int key, int value) {
        if(mp.find(key)!=mp.end())
        {
            mp[key].second=value;
            makeMostFrequent(key);
            return;
        }
        else
        {
            //Dont't think about the capacity now
            dll.push_front(key); //Push at the start coz most frequent element
            mp[key]={dll.begin(),value}; //Push entry in the map
            makeMostFrequent(key);
            cap--;
        }
        if(cap<0)
        {
            mp.erase(dll.back()); //Delete the entry in map
            dll.pop_back(); //Delete the Less frequent element
            cap++;
        }
        }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */