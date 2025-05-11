class Solution {
public:
    bool divideArray(vector<int>& nums) {
        //A1: TC:O(N) SC:O(distinct(nums[i]))
        
        unordered_map<int,int>m;
        for(auto val:nums) m[val]++;

        for(auto val:m) if(val.second%2==1) return 0;
        return 1;
        

        //A2: take array of 500 mark all true and toggle it when element comes if in pair , it will again comes as true if not it will false,if any one element in array is false , we will return 0
    }
};