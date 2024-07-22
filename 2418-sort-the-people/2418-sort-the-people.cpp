class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights)     {
        map<int,string>m;
        for(int i=0;i<names.size();i++)
        {
            m[heights[i]]=names[i];
        }
        //sort(m.begin(),m.end());
        
        vector<string>ans;
        for(auto val:m)
        {
            ans.push_back(val.second);
        }
        reverse(ans.begin(),ans.end());
        return ans;
        
    }
};