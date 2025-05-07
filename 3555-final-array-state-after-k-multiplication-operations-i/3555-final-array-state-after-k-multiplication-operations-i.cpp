class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        vector<int>ans(nums.size());
        for(int i=0;i<nums.size();i++)
        {
            pq.push({nums[i],i});
        }

        while(k--)
        {
            auto minEle=pq.top();
            pq.pop();
            minEle.first*=multiplier;
            pq.push(minEle);
        }

        while(!pq.empty())
        {
            auto ele=pq.top();
            pq.pop();

            ans[ele.second]=ele.first;
        }
        return ans;

    }
};