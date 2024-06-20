//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

//T.C : O(N) + O(N+2N)
//T.C : O(N)
class Solution{
  public:
    // arr[] : the input array
    // N : size of the array arr[]
    
    //Function to return length of longest subsequence of consecutive integers.
    int findLongestConseqSubseq(int a[], int n)
    {
      //Your code here
      int longest=1;
      unordered_set<int>s;
      for(int i=0;i<n;i++)
      {
          s.insert(a[i]);
      }
      
      for(auto val:s)
      {
          if(s.find(val-1)==s.end())
          {
              int c=1;
              while(s.find(val+1)!=s.end())
              {
                  c++;
                  val++;
              }
                longest=max(longest,c);
          }
      }
      return longest;
    }
};

//{ Driver Code Starts.
 
// Driver program
int main()
{
 int  t,n,i,a[100001];
 cin>>t;
 while(t--)
 {
  cin>>n;
  for(i=0;i<n;i++)
  cin>>a[i];
  Solution obj;
  cout<<obj.findLongestConseqSubseq(a, n)<<endl;
 }
      
    return 0;
}
// } Driver Code Ends