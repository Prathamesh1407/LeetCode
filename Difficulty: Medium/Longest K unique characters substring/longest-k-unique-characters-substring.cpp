//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    int longestKSubstr(string s, int k) {
    // your code here
    
    //TC : O(N + N + log(256))
    //SC : O(256)
    int left=0,right=0,res=0;
    unordered_map<char,int>m;
    while(right<s.length())
    {
        m[s[right]]++;
        
        while(m.size()>k)
        {
            m[s[left]]--;
            if(m[s[left]]==0) m.erase(s[left]);
            left++;
        }
        if(m.size()==k) res=max(res,right-left+1);
        right++;
    }
    return res?res:-1;
    
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int k;
        cin >> k;
        Solution ob;
        cout << ob.longestKSubstr(s, k) << endl;
    }
}

// } Driver Code Ends