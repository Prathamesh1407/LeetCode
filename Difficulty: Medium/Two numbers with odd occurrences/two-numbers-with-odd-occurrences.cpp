//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution{
    public:
    vector<long long int> twoOddNum(long long int a[], long long int n)  
    {
        // code here
        long long xorr=0;
        
        for(int i=0;i<n;i++) xorr^=a[i];
        
        long long firstDiffBit=(xorr&(xorr-1))^xorr;
        long long bucket1=0,bucket2=0;
        for(int i=0;i<n;i++)
        {
            if(a[i]&firstDiffBit) bucket1^=a[i];
            else bucket2^=a[i];
        }
        if(bucket1>bucket2) return {bucket1,bucket2};
        return {bucket2,bucket1};
        
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        long long int N;
        cin>>N;
        long long int Arr[N];
        for(long int i = 0;i < N;i++)
        cin>>Arr[i];
        Solution ob;
        vector<long long int>ans=ob.twoOddNum(Arr,N);
        for(long long int i=0;i<ans.size();i++)cout<<ans[i]<<" ";
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends