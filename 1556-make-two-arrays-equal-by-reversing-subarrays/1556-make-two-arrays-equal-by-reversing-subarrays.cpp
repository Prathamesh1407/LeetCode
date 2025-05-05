class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        //A1: TC: O(m+2*n) SC:O(1001)
        /*
        vector<int>v1(1001,0);
        vector<int>v2(1001,0);

        for(auto val:target) v1[val]+=1;
        for(auto val:arr) v2[val]+=1;

        for(auto val:arr)
        {
            if(v1[val]!=v2[val]) return 0;
        }
        return 1;
        */

        //A2: TC:O(disntict(m+n)) SC:O(disntict(m))

        unordered_map<int,int>m;
        for(auto val:target) m[val]++;
        for(auto val:arr)
        {
            if(m[val]==0) return 0;
            m[val]--;
        }
        return 1;

    }
};