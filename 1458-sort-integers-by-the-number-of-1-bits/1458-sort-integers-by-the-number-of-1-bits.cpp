class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        vector<int>ans=arr;
        auto lambda=[&](int &a,int &b){
            int ca=__builtin_popcount(a);
            int cb=__builtin_popcount(b);

            if(ca==cb) return a<b;
            return ca<cb;
        };
        sort(ans.begin(),ans.end(),lambda);
        return ans; 
    }
};