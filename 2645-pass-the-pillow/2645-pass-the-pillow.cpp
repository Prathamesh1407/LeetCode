class Solution {
public:
    int passThePillow(int n, int time) {
        if(time>=n)
        {
            bool toLast=(time/(n-1)%2)==1;
            int rem=time%(n-1);
            return toLast?n-rem:1+rem;
        }
        else
        {
            return time+1;
        }
    }
};