class Solution {
    int findMax(vector<int>& piles)
    {
        int maxi=piles[0];
        for(auto val:piles)
        {
            if(val>maxi) maxi=val;
        }
        return maxi;
    }
    long long solve(vector<int>& piles,int minHours)
    {
        long long ans=0;
        for(auto val:piles)
        {
            ans+=ceil((double)val/(double)minHours);
        }
        return ans;
    }
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        //Consider 3,6,7,11 4 is the minimum number that can be ended up eating in 8 hrs and after 4 all are valid numbers but we have to find the minimum number so search space is from 1 to max(piles) and for the minimum number move to the left
        int maxi=findMax(piles);
        int low=1,high=maxi;
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            long long temp=solve(piles,mid);
            if(temp<=h)
            {
                high=mid-1;
            }
            else low=mid+1;
        }
        return low;
    }
};