//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
    int solve(int n,vector<int>height,vector<int>&dp)
    {
        if(n==0) return 0;
        if(dp[n]!=-1) return dp[n];
         int left=solve(n-1,height,dp)+abs(height[n-1]-height[n]);
         int right=INT_MAX;
         if(n>1)
         {
            right=solve(n-2,height,dp)+abs(height[n-2]-height[n]);
         }
         return dp[n]=min(left,right);
    }
  public:
    int minimumEnergy(vector<int>& height, int n) {
        // Code here
        vector<int>dp(n,-1);
        //return solve(n-1,height,dp);
        //int prev2=0,prev=0,curri;
        dp[0]=0;
        for(int i=1;i<n;i++)
        {
            int left=dp[i-1]+abs(height[i-1]-height[i]);
            int right=INT_MAX;
            if(i>1)
            {
                right=dp[i-2]+abs(height[i-2]-height[i]);
            }
            dp[i]=min(left,right);
        }
        return dp[n-1];
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        Solution obj;
        cout << obj.minimumEnergy(arr, N) << "\n";
    }
    return 0;
}
// } Driver Code Ends