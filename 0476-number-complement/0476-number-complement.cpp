class Solution {
public:
    int findComplement(int num) {
        //A1: TC: O(Number of bits in num)
        /*
        int num_bits=int(log2(num))+1;
        int XOR=num;
        //Xor with 1 will flip the bit 
        for(int i=0;i<num_bits;i++)
        {
            XOR^=(1<<i);
        }
        return XOR;
        */

        //A2: TC: O(1) Will create a mask here

        //If we do it like 1<<num_bits if num_bits=3 1000 means 8 -1 will give us 7 0111 and we'll get our mask for XOR

        int num_bits=int(log2(num))+1;
        unsigned int mask=(1U<<num_bits)-1;

        return num^mask;

    }
};