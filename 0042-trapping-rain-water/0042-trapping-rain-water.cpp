class Solution {
public:
    int trap(vector<int>& height) {
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
    }
};