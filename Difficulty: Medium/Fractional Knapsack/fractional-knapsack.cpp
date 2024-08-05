//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Item {
    int value;
    int weight;
};


// } Driver Code Ends
// class implemented
/*
struct Item{
    int value;
    int weight;
};
*/

class Solution {
    static bool compare(pair<int,int>&a,pair<int,int>&b)
    {
        return ((double)a.first/a.second)*1.0>=((double)b.first/b.second);
    }
  public:
    // Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int w, Item arr[], int n) {
        // Your code here
        
        //This is fractional Knapsack so we can take the fraction part but simply taking on highest weight will fail so we will sort it by the value/weight
        double ans=0;
        vector<pair<int,int>>v;
        for(int i=0;i<n;i++)
        {
            v.push_back({arr[i].value,arr[i].weight});
        }
        
        sort(v.begin(),v.end(),compare);
        
        for(int i=0;i<n && w>0;i++)
        {
            if(v[i].second<=w)
            {
                ans+=v[i].first;
                w-=v[i].second;
            }
            else
            {
                ans+=((double)v[i].first/v[i].second)*w;
                break;
            }
        }
        return ans;
    }
};



//{ Driver Code Starts.
int main() {
    int t;
    // taking testcases
    cin >> t;
    cout << setprecision(6) << fixed;
    while (t--) {
        // size of array and weight
        int n, W;
        cin >> n >> W;

        Item arr[n];
        // value and weight of each item
        for (int i = 0; i < n; i++) {
            cin >> arr[i].value >> arr[i].weight;
        }

        // function call
        Solution ob;
        cout << ob.fractionalKnapsack(W, arr, n) << endl;
    }
    return 0;
}
// } Driver Code Ends