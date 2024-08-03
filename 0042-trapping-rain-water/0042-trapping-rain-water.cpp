class Solution {
public:
    int trap(vector<int>& height) {
        /*
        //1st Approach
        //TC : O(2N)
        //SC : O(2N)
        int n=height.size();
        vector<int>pre,suff(n);
        int maxiPre=-1,maxiSuff=-1;
        for(int i=0;i<n;i++)
        {
            maxiPre=max(height[i],maxiPre);
            maxiSuff=max(height[n-i-1],maxiSuff);
            pre.push_back(maxiPre);
            suff[n-i-1]=maxiSuff;
        }
        int c=0;
        for(int i=0;i<n;i++)
        {
            c+=min(pre[i],suff[i])-height[i];
            //cout<<suff[i]<<" ";
        }
        return c;
        */
        
        //2ndApproach : 2-pointer Approach
        //TC : O(N)
        //SC : O(1)
        int l=0,n=height.size(),r=n-1,ans=0;
        int leftMax=0,rightMax=0;
        while(l<=r)
        {
            if(height[l]<height[r])
            {
                if(height[l]>=leftMax) leftMax=height[l];
                else ans+=leftMax-height[l];
                l++;
            }
            else
            {
                //height[l]>=height[r]
                if(height[r]>=rightMax) rightMax=height[r];
                else ans+=rightMax-height[r];
                r--;
            }
        }
        return ans;
    }
};