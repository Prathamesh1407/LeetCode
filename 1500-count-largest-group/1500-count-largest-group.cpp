class Solution {
    int calSum(int n)
    {
        int sum=0;
        while(n)
        {
            sum+=(n%10);
            n/=10;
        }
        return sum;
    }
public:
    int countLargestGroup(int n) {
        //37 because maximum sum can be 36 i.e 9999
        //TC: O(n*log digit)
        vector<int>v(37,0);
        int maxi=0;
        for(int i=1;i<=n;i++)
        {
            int sum=calSum(i);
            v[sum]++;
            maxi=max(maxi,v[sum]);
        }
        int ans=0;
        for(int i=0;i<=36;i++)
        {
            //cout<<v[i]<<" ";
            if(v[i]==maxi) ans++;
        }
        return ans;
    }
};