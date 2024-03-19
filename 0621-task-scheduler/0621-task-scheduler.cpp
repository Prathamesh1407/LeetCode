class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        if(n==0) return tasks.size();
        vector<int>v(26);
        for(int i=0;i<tasks.size();i++)
        {
            v[tasks[i]-'A']++;
        }
        //for(auto val:v) cout<<val<<" ";
        sort(v.begin(),v.end(),greater<int>());
        int idle_slots=(v[0]-1)*n;
        for(int i=1;i<26;i++)
        {
            idle_slots-=min(v[i],v[0]-1);
        }
        
        return idle_slots>0?(idle_slots+tasks.size()):tasks.size();
    }
};