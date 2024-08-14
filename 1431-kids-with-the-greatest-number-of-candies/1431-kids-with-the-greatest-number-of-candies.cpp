class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        vector<bool>ans;
        int maxi=0;
        for(auto val:candies)
        {
            maxi=max(maxi,val);
        }
        
        for(auto val:candies)
        {
            if(val==maxi || val+extraCandies>=maxi) ans.push_back(1);
            else ans.push_back(0);
        }
        return ans;
    }
};