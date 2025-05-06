class Solution {
public:
    int numberOfSteps(int num) {
        //if we meet 0 then its even and we divide it by 2 so res+=1 but if we encounter with 1 then its odd -1 and divide by 2 so 2 operations, res+=2

        //one Exception for the leftmost one there will be only -1 and it will become zero so at the end return res-1

        if(num==0) return 0;
        int res=0;
        while(num)
        {
            if(num&1)
            {
                //Its 1
                res+=2;
            }
            else
            {
                res+=1;
            }
            num>>=1;
        } 
        return res-1;
    }
};