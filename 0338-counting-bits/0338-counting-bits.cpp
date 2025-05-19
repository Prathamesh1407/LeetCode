class Solution {
    //If we use this function Time Complexity will be O(logn) overall n*logN
    int countSetBits(int n)
    {
        int cnt=0;

        while(n)
        {
            if((n&1)) cnt++;
            n>>=1;
        }
        return cnt;
    }
public:
    vector<int> countBits(int n) {
        vector<int>ans(n+1);

        for(int i=0;i<=n;i++)
        {
            //ans[i]=countSetBits(i);
            ans[i]=__builtin_popcount(i); //O(1)
        }
        return ans;
    }
};