class Solution {
public:
    int tribonacci(int n) {
        if(n<2) return n;
        int t0=0,t1=1,t2=1,tn=0;
        long long i=3,curr;
        for(int i=3;i<=n;i++)
        {
            curr=t0+t1+t2;
            t0=t1;
            t1=t2;
            t2=curr;
        }
        return t2;
    }
};