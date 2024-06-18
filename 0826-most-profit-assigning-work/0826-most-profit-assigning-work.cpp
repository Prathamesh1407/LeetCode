class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        vector<pair<int,int>>v;
        for(int i=0;i<profit.size();i++)
        {
            v.push_back({difficulty[i],profit[i]});
        }
        sort(v.begin(),v.end());
        
        sort(worker.begin(),worker.end());
        
        int i=0,j=0,ans=0,maxi=0;
        //priority_queue<int>pq;
        while(j<worker.size())
        {
            
            while(i<profit.size() && worker[j]>=v[i].first)
            {
                //pq.push(v[i].second);
                maxi=max(maxi,v[i].second);
                i++;
            }
            // if(!pq.empty()) 
            // {
            //     ans+=pq.top();
            // }
                ans+=maxi;
            j++;
        }
        return ans;
    }
};