
class Solution {
    static bool compare(pair<char,int>&p1,pair<char,int>&p2)
    {
        return p1.second>p2.second;
    }
public:
    string frequencySort(string s) {
        // TC : O(N + 123log123 + 122)
        // SC : O(123)
        /*
        vector<pair<char,int>>v(123);
        
        for(auto ch:s)
        {
            int freq=v[ch].second;
            v[ch]={ch,freq+1};
        }
        
        sort(v.begin(),v.end(),compare);
        string ans="";
        for(int i=0;i<122;i++)
        {
            int freq=v[i].second;
            char ch=v[i].first;
            
            if(freq==0) break;
            
            string temp(freq,ch);
            ans+=temp;
            
        }
        return ans;
        */
        
        //TC : O(N + M*log(M)) => O(N),  where N is the number of characters in the string and M is the number of UNIQUE characters in the string, and in this case M <= min(62, N).
        
        //SC : O(1)
        priority_queue<pair<int,char>>pq;
        unordered_map<char,int>m;
        for(auto val:s)
        {
            m[val]++;
            
        }
        for(auto val:m)
        {
           pq.push({val.second,val.first});     
        }
        string ans="";
        
        while(!pq.empty())
        {
            auto temp=pq.top();
            pq.pop();
            string t(temp.first,temp.second);
            ans+=t;
        }
        return ans;
    }
};