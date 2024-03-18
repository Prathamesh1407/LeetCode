class Solution {
    static bool compare(vector<int>&a,vector<int>&b)
    {
        if(a[1]<b[1]) return true;
        if(a[1]==b[1] && a[0]<b[0]) return true;
        return false;
    }
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        vector<vector<int>>ans;
        sort(points.begin(),points.end(),compare);
        int end=points[0][1];
        int c=1;
        int n=points.size();
        for(int i=0;i<n;i++)
        {
            if(points[i][0]>end)
            {
                c++;
                end=points[i][1];
            }
        }
        return c;
    }
};