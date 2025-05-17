class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        vector<int>v(101,0);
        int op=0;
        for(int i=0;i<nums.size();i++) v[nums[i]]++;
        //for(int i=0;i<=100;i++) cout<<v[i]<<" ";

        for(int i=100;i>=0;i--)
        {
            if(i==k)
            {
                if(v[i]!=nums.size()) return -1;
                return op;
            }
            
            if(v[i]!=0)
            {
                //cout<<i<<" ";
                if(i>=1) 
                {
                    int temp=v[i];
                    while(v[i-1]==0 && i-1>k)
                    {
                        i--;
                    }
                    v[i-1]+=temp;
                }
                op++;
            }
        }
        return op;
    }
};