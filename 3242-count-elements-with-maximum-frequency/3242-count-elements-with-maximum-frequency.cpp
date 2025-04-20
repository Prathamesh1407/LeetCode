class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {

        //Here constraints are less , so we can also use array of 100

        //A1: Two Pass Approach , keep Track of maximum count and compare it in 2nd pass
        /*
        unordered_map<int,int>m;
        int maxCount=INT_MIN;
        for(int i=0;i<nums.size();i++)
        {
            m[nums[i]]++;
            maxCount=max(maxCount,m[nums[i]]);
        }
        int ans=0;
        for(auto val:m)
        {
            if(val.second==maxCount) ans++;
        }
        return ans*maxCount;
        */

        //A2: Single pass solution
        
        // Keep track of maximum frequency and keep counting how many elements are of same frequency and if find it greater than max freq repeat the process
        int maxFreq=0,count=1;
        vector<int>arr(101,0);
        for(int i=0;i<nums.size();i++)
        {
            arr[nums[i]]++;
            if(maxFreq==arr[nums[i]]) count++;
            if(maxFreq<arr[nums[i]])
            {
                maxFreq=arr[nums[i]];
                count=1;
            }
        }

        return count*maxFreq;
    }
};
