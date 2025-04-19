class Solution {
public:
    int minOperations(string s) {
        int one=0,zero=0;
        char oneChar='1',zeroChar='0';

        for(auto val:s)
        {
            if(oneChar!=val)
            {
                one++;
            }
            if(zeroChar!=val)
            {
                zero++;
            }
            oneChar=oneChar^'1'^'0';
            zeroChar=zeroChar^'1'^'0';
        }

        cout<<one<<" "<<zero;
        return min(one,zero);
    }
};