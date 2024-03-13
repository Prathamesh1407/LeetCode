class Solution {
public:
    int pivotInteger(int n) {
        if(n==1) return 1;
        long long int i=1,j=n;
        int sum=n*(n+1)/2,fsum;
        while(i<n)
        {
            fsum=i*(i+1)/2;
            if(sum-fsum+i==fsum) return i;
            i++;
        }
        return -1;
    }
};