class Solution {
public:
    int minFlips(int a, int b, int c) {
        int flips=0;
        while(a || b || c)
        {
            int currBitC=(c&1);
            cout<<currBitC<<" ";
            if(((a&1) | (b&1))!=currBitC)
            {
                if(currBitC==1)
                {
                    flips+=1;
                }
                else
                {
                    if(((a&1)&(b&1))==1) flips+=2;
                    else flips+=1;
                }
            }
            a>>=1;
            b>>=1;
            c>>=1;
        }
        return flips;
    }
};