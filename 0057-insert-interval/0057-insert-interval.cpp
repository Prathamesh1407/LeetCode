class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newI) {
        vector<vector<int>>ans;
        int start=newI[0],end=newI[1];
        int i=0,n=intervals.size();
        while(i<n && intervals[i][1]<start)
        {
            ans.push_back(intervals[i]);
            i++;
        }
        while(i<n && intervals[i][0]<=end)
        {
            newI={min(intervals[i][0],newI[0]),max(intervals[i][1],newI[1])};
            i++;
        }
        ans.push_back(newI);
        while(i<n)
        {
            ans.push_back(intervals[i]);
            i++;
        }
        return ans;
    }
};