class Solution {
public:
    int maxProductDifference(vector<int>& nums) {
        int smax=0,smin=INT_MAX,mini=INT_MAX,maxi=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]>maxi) 
            {
                smax=maxi;
                maxi=nums[i];
            }
            else 
            {
                smax=max(smax,nums[i]);
            }

            if(nums[i]<mini)
            {
                smin=mini;
                mini=nums[i];
            }
            else
            {
                smin=min(smin,nums[i]);
            }
        }

        //cout<<smax<<" "<<maxi<<endl<<smin<<" "<<mini;


        return (smax*maxi)-(smin*mini);
    }
};