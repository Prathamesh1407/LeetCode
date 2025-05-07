class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        unordered_set<int>st;

        for(auto val:arr)
        {
            if(st.find(val*2)!=st.end()) return 1;
            if(val%2==0 && st.find(val/2)!=st.end()) return 1;
            st.insert(val);
        }
        return 0;
    }
};