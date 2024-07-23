class Solution {
    bool canPlaceCows(vector<int>& position,int maxDistance,int m)
    {
        int cowsCount=1,last=position[0]; //Cause 1st cow will be placed at 1st pos
        int n=position.size();
        for(int i=1;i<n;i++)
        {
            if(position[i]-last>=maxDistance) 
            {
                cowsCount++;
                last=position[i];
            }
            if(cowsCount==m) break;
        }
        return cowsCount==m;
    }
public:
    int maxDistance(vector<int>& position, int m) {
        //Similar to aggresive cows
        sort(position.begin(),position.end());
        
        int maxi=position[position.size()-1],mini=position[0];
        int low=1,high=maxi-mini;
        
        while(low<=high)
        {
            int mid=(low+high)/2;
            
            if(canPlaceCows(position,mid,m))
            {
                low=mid+1;
            }
            else high=mid-1;
        }
        return high;
    }
};