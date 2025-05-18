class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        //A1:
        /*
        unordered_map<string,int>m;
        int ans=0;
        for(auto val:dominoes)
        {
            m[to_string(min(val[0],val[1]))+to_string(max(val[0],val[1]))]++;
        }

        for(auto val:m)
        {
            ans+=((val.second*(val.second-1))/2);
        }
        return ans;
        */

        //A2: Using unique answer trick a*10+b

        vector<int>v(100,0);
        int ans=0;
        for(auto val:dominoes)
        {
            int mini=min(val[0],val[1]);
            int maxi=max(val[0],val[1]);
            v[mini*10+maxi]++;
        }
        for(auto val:v)
        {
            ans+=((val*(val-1))/2);
        }
        return ans;
    }
};