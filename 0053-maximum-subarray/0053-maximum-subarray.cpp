class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int s=0,maxi=INT_MIN,start,ansStart,ansEnd;
        for(int i=0;i<nums.size();i++)
        {
            if(s==0) start=i;
            s+=nums[i];
            //maxi=max(maxi,s);
            
                if(s>maxi)
                {
                    //For printing the subarray
                    ansStart=start;
                    ansEnd=i;
                    maxi=s;
                }
           
            if(s<0) s=0;
        }
        for(int i=ansStart;i<=ansEnd;i++) cout<<nums[i]<<" ";
        return maxi;
    }
};