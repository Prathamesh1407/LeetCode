class Solution {
    vector<int> solve(int row)
    {
        long long ans=1;
        vector<int>nrow;
        nrow.push_back(1);
        for(int col=1;col<row;col++)
        {
            ans*=(row-col);
            ans/=col;
            nrow.push_back(ans);
        }
        return nrow;
    }
public:
    vector<vector<int>> generate(int n) {
        if(n==1) return {{1}};
        vector<vector<int>>v;
        for(int i=1;i<=n;i++)
        {
            v.push_back(solve(i));
        }
        return v;
    }
};