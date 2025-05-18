class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int ans=0;
        for(auto val:nums)
        {
            if(val==1) continue;
            if((int)(floor(log10(val))+1)%2==0) ans++;
        }
        return ans;
    }
};