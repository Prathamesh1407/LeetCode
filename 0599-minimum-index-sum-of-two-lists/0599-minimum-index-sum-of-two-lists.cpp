class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        unordered_map<string,int>m,p;
        int i=0;
        vector<string>ans;
        for(auto val:list1) 
        {
            m[val]=i;
            i++;
        }
        i=0;
        for(auto val:list2) 
        {
            if(m.find(val)!=m.end())
            {
                p[val]=m[val]+i;
            }
            i++;
        }
        int mini=10000;
        string s;
        for(auto val:p)
        {
            if(val.second<=mini)
            {
                mini=min(mini,val.second);
            }
        }
        for(auto val:p)
        {
            if(val.second==mini)
            {
                ans.push_back(val.first);  
            }
        }
        return ans;
        
    }
};