class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n=nums.size();
        stack<int>st;
        vector<int>nge(n);
        for(int i=2*n-1;i>=0;i--) //To make imaginary copy of original array
        {
            while(st.empty()==false && nums[i%n]>=st.top())
            {
                st.pop();
            }
            if(i<n)
            {
                //in original Array
                if(st.empty()==false) nge[i]=st.top();
                else nge[i]=-1; 
            }
            st.push(nums[i%n]);
        }
        return nge;
    }
};