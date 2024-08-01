class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int n=nums.size();
        /*
        for(int i=0;i<nums.size();)
        {
            if(nums[i]==1)
            {
                i++;
                int c=0;
                while(i<n && nums[i]!=1)
                {
                    i++;
                    c++;
                }
                //cout<<c<<" ";
                if(c<k && i!=n) return 0;
            }
            else i++;
        }
        
        return 1;
        */
        
        int prev=-k-1;
        
        for(int i=0;i<n;i++)
        {
            if(nums[i]==1)
            {
                if(i-prev<=k) return 0;
                prev=i;
            }
        }
        return 1;
    }
};