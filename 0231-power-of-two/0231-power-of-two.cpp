class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n<=0) return false;
        if((n&(n-1))==0) return true;
        return false;


        //A2: count set bits as only 1 set bit will be there in power of two

        //A3: 
        /*
            As range is given till 2^31-1 so largest power of two would be 2^30
            2^30= 2*2*2*........(30)*2
            if n is power of 2 all prime factors will be 2 only 
            so if 2^30 % n == 0 that means it's a power of 2
        */
    }
};