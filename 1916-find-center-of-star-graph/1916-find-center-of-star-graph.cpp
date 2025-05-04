class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        unordered_map<int,vector<int>>m;

        for(auto &val:edges)
        {
            
                int u=val[0],v=val[1];

                m[u].push_back(v);
                m[v].push_back(u);
            
        }
        for(auto val:m)
        {
            if(val.second.size()==edges.size()) return val.first;
        }

        return -1;
    }
};