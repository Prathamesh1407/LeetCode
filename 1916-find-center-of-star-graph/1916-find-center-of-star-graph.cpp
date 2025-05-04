class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {

        //A1:
        /*
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
        */

        if(edges[0][1]==edges[1][0]) return edges[1][0];
        if(edges[0][1]==edges[1][1]) return edges[1][1];
        if(edges[0][0]==edges[1][0]) return edges[0][0]; 
        if(edges[0][0]==edges[1][1]) return edges[0][0];
        return -1;
    }
};