class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {

        //A1: Approach 1 TC:O(n) SC:O(n)
        /*
        vector<int>ans(nums.size(),0);
        int k=0;

        for(int i=0;i<nums.size()-1;i++)
        {
            if(nums[i]!=0 && nums[i]==nums[i+1])
            {
                ans[k++]=nums[i]*2;
                nums[i+1]=0;
            }
            else if(nums[i]!=0) ans[k++]=nums[i];
        }
        if(nums[nums.size()-1]!=0) ans[k]=nums[nums.size()-1];
        return ans;
        */

        //A2: Inplace TC:O(n) SC:O(1) 2 pass
        /*
        int n=nums.size();
        for(int i=0;i<n-1;i++)
        {
            if(nums[i]!=0 && nums[i]==nums[i+1])
            {
                nums[i]*=2;
                nums[i+1]=0;
            }
        }

        int j=0;
        for(int i=0;i<n;i++)
        {
            if(nums[i]!=0) 
            {
                swap(nums[i],nums[j]);
                j++;
            }
        }
        return nums;
        */

        //A2: Inplace TC:O(n) SC:O(1) 1 pass
        int n=nums.size(),j=0;
        for(int i=0;i<n;i++)
        {
            if(i+1<n && nums[i]!=0 && nums[i]==nums[i+1])
            {
                nums[i]*=2;
                nums[i+1]=0;
            }
            if(nums[i]!=0)
            {
                if(i!=j)
                {
                    //means somewhere j is on 0
                    swap(nums[i],nums[j]);
                }
                j++;
            }
        }
        return nums;
    }
};