//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    int lenOfLongSubarr(int a[],  int n, int k) 
    { 
        // Complete the function
        unordered_map<int,int>preSum;
        //This is for if we encountered with sum from the first instead of if sum==k (sum,i+1) it will directly find sum-k which is 0 so that index-(-1) = ans
        preSum[0]=-1;
        
        int sum=0,len=0;
        for(int i=0;i<n;i++)
        {
            sum+=a[i];
            int rem=sum-k;
            if(preSum.find(rem)!=preSum.end())
            {
                len=max(len,i-preSum[rem]);
            }
            //this condition for if 2,0,0,3 and k=3 the longest is 0 ,0,3 if we updated without condition the final entry will (2,2) and at the time sum becomes 5 it will search for 5-k and then 3-2 will become 1 
            if(preSum.find(sum)==preSum.end())
            {
                preSum[sum]=i;
            }
        }
        return len;
    } 

};

//{ Driver Code Starts.

int main() {
	//code
	
	int t;cin>>t;
	while(t--)
	{
	    int n, k;
	    cin>> n >> k;
	    int a[n];
	    
	    for(int i=0;i<n;i++)
	        cin>>a[i];
	   Solution ob;
	   cout << ob.lenOfLongSubarr(a, n , k)<< endl;
	    
	}
	
	return 0;
}
// } Driver Code Ends