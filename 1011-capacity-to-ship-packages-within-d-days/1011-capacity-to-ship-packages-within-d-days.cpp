//TC : O(N * log2(sum-maxi))
//SC : O(1)
class Solution {
    int requiredDays(vector<int>& weights, int capacity)
    {
        int days=1,load=0;
        for(auto val:weights)
        {
            if(load+val>capacity)
            {
                days++;
                load=val;
            }
            else load+=val;
        }
        return days;
    }
public:
    int shipWithinDays(vector<int>& weights, int days) {
        //The search space will be of maximum element to the sum of whole array why only maximum number coz at the end every element should load in the ship i.e capacity of ship
        int sum=0,maxi=weights[0];
        for(auto val:weights)
        {
            sum+=val;
            maxi=max(maxi,val);
        }
        
        int low=maxi,high=sum;
        
        while(low<=high)
        {
            int mid=(low+high)/2;
            
            if(requiredDays(weights,mid)<=days)
            {
                high=mid-1;
            }
            else low=mid+1;
        }
        return low;
    }
};