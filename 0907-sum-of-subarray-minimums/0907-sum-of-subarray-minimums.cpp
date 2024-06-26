class Solution {
    void nextSmallerElement(vector<int>& arr,vector<int>&right,int n)
    {
        stack<int>st;
        
        for(int i=n-1;i>=0;i--)
        {
            if(st.empty()==true)
            {
                st.push(i);
                right[i]=n;
            }
            else
            {
                while(st.empty()==false && arr[st.top()]>arr[i])
                {
                    st.pop();
                }
                if(st.empty()==true)
                {
                    right[i]=n;
                }
                else
                {
                    right[i]=st.top();
                }
                st.push(i);
            }
        }
    }
    void previousSmallerElement(vector<int>& arr,vector<int>&left,int n)
    {
        stack<int>st;
        
        for(int i=0;i<n;i++)
        {
            if(st.empty()==true)
            {
                st.push(i);
                left[i]=-1;
            }
            else
            {
                while(st.empty()==false && arr[st.top()]>=arr[i])
                {
                    st.pop();
                }
                if(st.empty()==true)
                {
                    left[i]=-1;
                }
                else
                {
                    left[i]=st.top();
                }
                st.push(i);
            }
        }
    }
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n=arr.size();
        int mod=1e9+7;
        vector<int>left(n),right(n);
        nextSmallerElement(arr,right,n);
        previousSmallerElement(arr,left,n);
        long long sum=0;
        for(int i=0;i<n;i++)
        {
            long long nextSmallerCount=right[i]-i;
            long long previousSmallerCount=i-left[i];
            long long totalWays=nextSmallerCount*previousSmallerCount;

            sum=(sum+(totalWays*arr[i]))%mod;
        }
        return sum;
    }
};