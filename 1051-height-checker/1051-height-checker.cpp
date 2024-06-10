class Solution {
public:
    int heightChecker(vector<int>& heights) {
        int ans=0;
        int currHeight=1;
        
        vector<int>count(101);
        
        for(auto val:heights)
        {
            count[val]++;
        }
        
        for(auto val:heights)
        {
            while(count[currHeight]==0) currHeight++;
            
            if(val!=currHeight) ans++;
            count[currHeight]--;
        }
        return ans;
    }
};