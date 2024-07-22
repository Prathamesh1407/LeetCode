//TC:O(N * log2(maxi-mini))
//SC : O(1)
class Solution {
    bool possible(vector<int>&bloomDay,int day,int m,int k)
    {
        int c=0,ans=0;
        for(auto val:bloomDay)
        {
            if(val<=day)
            {
                //Bloom adjacent
                c++;
            }
            else
            {
                //Not adjacent
                ans+=(c/k);//count the no. of bouque could be made
                c=0;
            }
        }
        ans+=(c/k);
        return ans>=m;
    }
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        //The flowers will bloom only from the minimum to maximum element days so this is our search space
        if(1LL*m*k>bloomDay.size()) return -1;
        int maxi,mini;
        maxi=mini=bloomDay[0];
        for(auto val:bloomDay)
        {
            maxi=max(maxi,val);
            mini=min(mini,val);
        }
        int low=mini,high=maxi;
        while(low<=high)
        {
            int mid=(low+high)/2;
            if(possible(bloomDay,mid,m,k))
            {
                //we want minimum so search it on the left side
                high=mid-1;
            }
            else low=mid+1;
        }
        return low;
    }
};