class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        //unoredered_map<int,int>m;
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int freq=0;
        int left=0,right=0;
        long long res=0;
        int maxi=*max_element(nums.begin(),nums.end());
        while(right<nums.size())
        {
            if(nums[right]==maxi) freq++;
            
            while(freq==k)
            {
                res+=nums.size()-right;
                if(nums[left]==maxi) freq--;
                left++;
            }
            right++;
        }
        return res;
    }
};