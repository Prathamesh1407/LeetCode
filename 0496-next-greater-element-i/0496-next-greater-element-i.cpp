class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int>st;
        unordered_map<int,int>m;
        int n=nums2.size();
        //vector<int>nge(n);
        for(int i=n-1;i>=0;i--)
        {
            if(st.empty()==true)
            {
                st.push(nums2[i]);
                //nge[i]=-1;
                m[nums2[i]]=-1;
            }
            else
            {
                while(st.empty()==false && st.top()<nums2[i])
                {
                    st.pop();
                }
                if(st.empty()) 
                {
                    //nge[i]=-1;
                    m[nums2[i]]=-1;
                }
                else 
                {
                    //nge[i]=st.top();
                    m[nums2[i]]=st.top();
                }
                st.push(nums2[i]);
            }
        }
        n=nums1.size();
        vector<int>ans;
        for(int i=0;i<n;i++)
        {
            ans.push_back(m[nums1[i]]);
        }
        return ans;
    }
};