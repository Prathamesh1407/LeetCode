//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
    int solve(vector<vector<int>>&points, int day,int lastTask,vector<vector<int>>&dp)
    {
        if(dp[day][lastTask]!=-1) return dp[day][lastTask];
        if(day==0)
        {
            //Means it has no condition that which day to choose so maximum element will get selected
            int maxi=0;
            for(int task=0;task<3;task++)
            {
                if(task!=lastTask) maxi=max(maxi,points[day][task]);
            }
            return dp[day][lastTask]=maxi;
        }
        int maxi=0;
        for(int task=0;task<3;task++)
        {
            if(task!=lastTask)
            {
                int ans=points[day][task]+solve(points,day-1,task,dp);
                maxi=max(maxi,ans);
            }
        }
        return dp[day][lastTask]=maxi;
    }
  public:
    int maximumPoints(vector<vector<int>>& points, int n) {
        // Code here
        vector<vector<int>>dp(n,vector<int>(4,-1));
        
        //Memoization
        //return solve(points,n-1,3,dp);
        
        //Tabulation
        dp[0][0] = max(points[0][1], points[0][2]);
        dp[0][1] = max(points[0][0], points[0][2]);
        dp[0][2] = max(points[0][0], points[0][1]);
        dp[0][3] = max(points[0][0], max(points[0][1], points[0][2]));
        
        for(int day=1;day<n;day++)
        {
            for(int last=0;last<4;last++)
            {
                dp[day][last]=0;
                for(int task=0;task<3;task++)
                {
                    if(task!=last)
                    {
                        int ans=points[day][task]+dp[day-1][task];
                        dp[day][last]=max(dp[day][last],ans);
                    }
                }
            }
        }
        return dp[n-1][3];
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> points;
        for (int i = 0; i < n; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            points.push_back(temp);
        }

        Solution obj;
        cout << obj.maximumPoints(points, n) << endl;
    }
    return 0;
}
// } Driver Code Ends