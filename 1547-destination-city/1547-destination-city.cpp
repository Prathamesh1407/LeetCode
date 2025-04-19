class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        unordered_map<string,string>m;

        for(int i=0;i<paths.size();i++)
        {
            m[paths[i][0]]=paths[i][1];
        }

        string str=paths[0][0],ans="";

        while(m.find(str)!=m.end())
        {
            ans=m[str];
            str=m[str];
        }

        return ans;
    }
};