class Solution {
public:
    int differenceOfSums(int n, int m) {
        int sum=n*(n+1)/2,dsum=0;

        for(int i=1;i<=n;i++)
        {
            if(i%m!=0) dsum+=i;
        }
        return dsum-(sum-dsum);
    }
};