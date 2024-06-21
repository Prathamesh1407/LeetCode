class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& a) {
        int n=a.size(),start,end;
        sort(a.begin(),a.end());
        start=a[0][0];
        end=a[0][1];
        vector<vector<int>>ans;
        for(int i=1;i<n;i++)
        { 
            if(a[i][0]<=end)
            {
                end=max(end,a[i][1]);
            }
            else
            {
                ans.push_back({start,end});
                start=a[i][0];
                end=a[i][1];
            }
        }
        ans.push_back({start,end});
        return ans;
    }
};