class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        vector<int>ans(code.size(),0);
        if(k==0)
        {
            return ans;
        }
        int i,j,n=code.size();
        if(k>0)
        {
            i=1;
            j=k;
        }
        else 
        {
            i=n-abs(k);
            j=n-1;
        }

        int windowSum=0;

        for(int p=i;p<=j;p++)
        {
            windowSum+=code[p];
        }

        for(int k=0;k<n;k++)
        {
            ans[k]=windowSum;

            windowSum-=code[i%n];
            i++;

            windowSum+=code[(j+1)%n];
            j++;
        }
        return ans;
    }
};