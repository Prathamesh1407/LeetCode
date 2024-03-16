class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int,int>m;
        //m [count,index]
        m[0]=-1;
        int c=0,max_length=0;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            if(nums[i]==0) c--;
            if(nums[i]==1) c++;
            if(m.find(c)!=m.end())
            {
                max_length=max(max_length,i-m[c]);
            }
            else m[c]=i;
        }
        return max_length;
    }
};