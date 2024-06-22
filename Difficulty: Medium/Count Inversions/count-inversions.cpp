//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
    long long merge(long long a[],int low,int mid,int high)
    {
        vector<long long>temp;
        int left=low,right=mid+1;
        long long c=0;
        while(left<=mid && right<=high)
        {
            if(a[left]<=a[right])
            {
                temp.push_back(a[left++]);
            }
            else
            {
                c+=mid-left+1;
                temp.push_back(a[right++]);
            }
        }
        while(left<=mid)
        {
            temp.push_back(a[left++]);
        }
        while(right<=high)
        {
            temp.push_back(a[right++]);
        }
    
        for(int i=low;i<=high;i++)
        {
            a[i]=temp[i-low];
        }
        return c;
    }
long long mergeSort(long long a[],int n,int low,int high)
{
    long long c=0;
    if(low==high) return c;
    int mid=(low+high)/2;
    c+=mergeSort(a,n,low,mid);
    c+=mergeSort(a,n,mid+1,high);
    c+=merge(a,low,mid,high);
    return c;
}
  public:
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.
    long long int inversionCount(long long a[], int n) {
        // Your Code Here
        return mergeSort(a,n,0,n-1);
    }
};

//{ Driver Code Starts.

int main() {

    long long T;
    cin >> T;

    while (T--) {
        int N;
        cin >> N;

        long long A[N];
        for (long long i = 0; i < N; i++) {
            cin >> A[i];
        }
        Solution obj;
        cout << obj.inversionCount(A, N) << endl;
    }

    return 0;
}

// } Driver Code Ends