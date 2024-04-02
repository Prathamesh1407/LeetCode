class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int el,c=0,c1=0;
        for(auto val:nums)
        {
            if(c==0)
            {
                c=1;
                el=val;
            }
            else if(el==val) c++;
            else c--;
        }
        for(auto val:nums) if(val==el) c1++;
        if(c1>nums.size()/2) return el;
        return -1;
    }
};