class Solution {
    vector<int> nextSmallerElement(vector<int>heights)
    {
        stack<int>st;
        int n=heights.size();
        st.push(-1);
        vector<int>ans(n);
        for(int i=n-1;i>=0;i--)
        {
            while(st.top()!=-1 && heights[st.top()]>=heights[i])
            {
                st.pop();
            }
            //top is the smallest element
            ans[i]=st.top();
            st.push(i);
        }
        return ans;
    }
    vector<int> previousSmallerElement(vector<int>heights)
    {
        stack<int>st;
        int n=heights.size();
        st.push(-1);
        vector<int>ans(n);
        for(int i=0;i<n;i++)
        {
            while(st.top()!=-1 && heights[st.top()]>=heights[i])
            {
                st.pop();
            }
            //top is the smallest element
            ans[i]=st.top();
            st.push(i);
        }
        return ans;
    }
    int largestRectangleArea(vector<int>heights)
    {
        vector<int>next=nextSmallerElement(heights);
        vector<int>previous=previousSmallerElement(heights);
        int n=heights.size();
        int area=INT_MIN;
        for(int i=0;i<n;i++)
        {
            int l=heights[i];

            if(next[i]==-1)
            {
                next[i]=n;
            }
            int b=next[i]-previous[i]-1;

            int newarea=l*b;
            area=max(newarea,area);
        }
        return area;
    }
public:
    int maximalRectangle(vector<vector<char>>& v) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        vector<vector<int>>matrix;
        for(int i=0; i<v.size(); i++){
            vector<int> temp;
            for(int j=0; j<v[0].size(); j++){
                temp.push_back(v[i][j] - '0');
            }
            matrix.push_back(temp);
        }
        int area=largestRectangleArea(matrix[0]);
        
        for(int i=1;i<matrix.size();i++)
        {
            for(int j=0;j<matrix[0].size();j++)
            {
                if(matrix[i][j]!=0) matrix[i][j]+=matrix[i-1][j];
            }
            //Now whole row is updated
            int newArea=largestRectangleArea(matrix[i]);
            area=max(area,newArea);
        }
        return area;
    }
};