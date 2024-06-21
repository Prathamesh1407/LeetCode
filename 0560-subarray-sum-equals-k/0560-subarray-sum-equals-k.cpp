class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int c=0,sum=0,n=nums.size();
        unordered_map<int,int>m;
        m[0]=1;
        
        for(int i=0;i<n;i++)
        {
            sum+=nums[i];
            int rem=sum-k;
            if(m.find(rem)!=m.end())
            {
                c+=m[rem];
            }
            m[sum]++;
            
        }
        return c;
    }
};