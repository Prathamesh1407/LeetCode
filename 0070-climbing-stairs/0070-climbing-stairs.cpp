class Solution {
public:
    int climbStairs(int n) {
       
        long long int t1=0,t2=1,nxt;
       
        for(int i=1;i<=n+1;i++)
        {
            nxt=t1+t2;
            t1=t2;
            t2=nxt;
        }
        return t1;
    }
};