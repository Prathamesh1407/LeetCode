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
    
    
    void nextGreaterElement(vector<int>& arr,vector<int>&rightG,int n)
    {
        stack<int>st;
        
        for(int i=n-1;i>=0;i--)
        {
            if(st.empty()==true)
            {
                st.push(i);
                rightG[i]=n;
            }
            else
            {
                while(st.empty()==false && arr[st.top()]<arr[i])
                {
                    st.pop();
                }
                if(st.empty()==true)
                {
                    rightG[i]=n;
                }
                else
                {
                    rightG[i]=st.top();
                }
                st.push(i);
            }
        }
    }
    void previousGreaterElement(vector<int>& arr,vector<int>&leftG,int n)
    {
        stack<int>st;
        
        for(int i=0;i<n;i++)
        {
            if(st.empty()==true)
            {
                st.push(i);
                leftG[i]=-1;
            }
            else
            {
                while(st.empty()==false && arr[st.top()]<=arr[i])
                {
                    st.pop();
                }
                if(st.empty()==true)
                {
                    leftG[i]=-1;
                }
                else
                {
                    leftG[i]=st.top();
                }
                st.push(i);
            }
        }
    }
public:
    long long subArrayRanges(vector<int>& arr) {
        int n=arr.size();
        vector<int>left(n),right(n),leftG(n),rightG(n);
        
        nextSmallerElement(arr,right,n);
        previousSmallerElement(arr,left,n);
        
        nextGreaterElement(arr,rightG,n);
        previousGreaterElement(arr,leftG,n);
        
        long long sumS=0,sumG=0;
        for(int i=0;i<n;i++)
        {
            long long nextSmallerCount=right[i]-i;
            long long previousSmallerCount=i-left[i];
            
            long long nextGreaterCount=rightG[i]-i;
            long long previousGreaterCount=i-leftG[i];
            
            long long totalWaysS=nextSmallerCount*previousSmallerCount;
            
            long long totalWaysG=nextGreaterCount*previousGreaterCount;

            sumS=(sumS+(totalWaysS*arr[i]));
            sumG=(sumG+(totalWaysG*arr[i]));
        }
        return sumG-sumS;
    }
};