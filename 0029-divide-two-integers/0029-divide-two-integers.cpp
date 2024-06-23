class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend==divisor) return 1;
        bool sign=1; //+ve
        
        if(dividend>0 && divisor<0) sign=0;//-ve
        if(dividend<0 && divisor>0) sign=0;
        
        long n=abs(dividend); //we can store -2^31 to 2^31 -1 if abs(-2^31) it will be 2^31 = overflow 
        long d=abs(divisor);
        int ans=0;
        while(n>=d)
        {
            int c=0;
            while(n>=(d<<(c+1))) c++; //d*2^(c+1)
            ans+=(1<<c);
            n-=(d<<c);
        }
        if(ans==(1<<31) && sign==1) return INT_MAX;
        if(ans==(1<<31) && sign==0) return INT_MIN;
        
        return sign?ans:ans*(-1);
    }
};