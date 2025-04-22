class Solution {
public:
    int findMaxK(vector<int>& nums) {
        /*
        unordered_map<int,int>m;
        int maxi=INT_MIN;
        for(auto val:nums)
        {
            m[val]++;

            if(m.find(val*-1)!=m.end())
            {
                maxi=max(abs(val),maxi);
            }
        }
        return maxi==INT_MIN?-1:maxi;
        */

        // A2: As constrains are less we can directly use array

        /*
            Now numbers can be -ve how to index them
            -1000 <= nums[i] <= 1000
            total 2001 elements
            add -ve index with highest limit here 1000
            -1000 + 1000 = 0 so -1000 will be placed at 0 index
            if -3 we want to find its counterpart then in array -(-3) = 3 1000 + 3 = 1003 th index will be -3's counterpart
        */

        vector<int>arr(2001,0);
        int maxi=-1;
        for(auto val:nums)
        {
            if(arr[-val+1000]==1)
            {
                //got counterpart 
                maxi=max(maxi,abs(val));
            }
            arr[val+1000]=1;

        }
        return maxi;
    }
};