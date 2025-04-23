class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        priority_queue<pair<int,int>,vector<pair<int,int>>>pq; //Max Heap

        for(int i=0;i<score.size();i++)
        {
            pq.push({score[i],i});
        }
        vector<string>ans(score.size());
        int rank=1;

        while(!pq.empty())
        {
            auto entry=pq.top();
            pq.pop();

            if(rank==1) ans[entry.second]="Gold Medal";
            else if(rank==2) ans[entry.second]="Silver Medal";
            else if(rank==3) ans[entry.second]="Bronze Medal";
            else ans[entry.second]=to_string(rank);

            rank++;
        }
        return ans;
    }
};