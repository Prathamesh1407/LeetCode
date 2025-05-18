class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        int c=0;

        for(auto val:arr)
        {
            if(val&1) c++;
            else c=0;
            if(c==3) return 1;
        }
        return 0;
    }
};