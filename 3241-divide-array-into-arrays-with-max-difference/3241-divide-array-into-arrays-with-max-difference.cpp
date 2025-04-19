class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());

        vector<vector<int>>ans;
        for(int i=0;i<nums.size();i+=3)
        {
            /*
            int temp=nums[i];
            vector<int>v;

            while(i<nums.size() && temp+k>=nums[i])
            {
                v.push_back(nums[i]);
                if(v.size()!=3) i++;
                else break;
            }
            if(v.size()!=3) return {};
            ans.push_back(v);
            */

            if(nums[i+2]>nums[i]+k) return {};
            ans.push_back({nums[i],nums[i+1],nums[i+2]});
        }

        return ans;
    }
};