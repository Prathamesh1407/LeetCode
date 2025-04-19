class Solution {
public:
    int maxScore(string s) {
        // A1: we wanted left side zero count and right side ones count so we'll count zero while traversing and will 1st count of ones 2 pass solution

        /*
        int totOnes=0,zeros=0,ones=0,ans=0;
        for(auto val:s)
        {
            if(val=='1') totOnes++;
        } 

        for(int i=0;i<=s.length()-2;i++)
        {
            if(s[i]=='0') zeros++;
            else ones++;

            ans=max(ans,zeros+(totOnes-ones));
        }
        return ans;
        */

        //A2: 1 pass solution let's formulate this 
        /*
            score= Zl + Or ----- (1)
            Ot= Ol + Or
            Or=Ot-Ol
            put this in 1
            score=Zl + (Ot-Ol)
            score=(Zl-Ol) + Ot (constant)
            only had to calculate the left zeros and ones count
        */

        int ones=0,zeros=0,ans=INT_MIN;

        for(int i=0;i<=s.length()-2;i++)
        {
            if(s[i]=='1') ones++;
            else zeros++;

            ans=max(ans,zeros-ones);
        }
        if(s[s.length()-1]=='1') ones++; //for Final total count of one
        return ans+ones;
    }
};