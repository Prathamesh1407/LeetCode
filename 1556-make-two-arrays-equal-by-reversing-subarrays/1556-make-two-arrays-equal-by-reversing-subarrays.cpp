class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        vector<int>v1(1001,0);
        vector<int>v2(1001,0);

        for(auto val:target) v1[val]+=1;
        for(auto val:arr) v2[val]+=1;

        for(auto val:arr)
        {
            if(v1[val]!=v2[val]) return 0;
        }
        return 1;
    }
};