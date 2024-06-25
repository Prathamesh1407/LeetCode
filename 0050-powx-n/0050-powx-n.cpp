//TC : O(log2n)
class Solution {
public:
    double myPow(double x, int n) {
        double ans=1;
        int m=n;
        n=abs(n);
        while(n>0)
        {
            if(n&1) 
            {
                ans*=x;
                n=n-1;
            }
            else
            {
                n=n>>1;
                x=x*x;
            }
        }
        return m>=0?ans:1.0/ans;
    }
};