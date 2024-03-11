class Solution {
public:
    string customSortString(string order, string s) {
        unordered_map<char,int>m;
        for(int i=0;i<order.length();i++)
        {
            m[order[i]]=0;
        }
        
        for(auto val:s)
        {
            if(m.find(val)!=m.end()) m[val]++;
        }
        
        string ans;
        for(auto val:order)
        {
            ans.append(m[val],val);
        }
        
        for(auto val:s)
        {
            if(m.find(val)==m.end()) ans+=val;
        }
        return ans;
        
    }
};