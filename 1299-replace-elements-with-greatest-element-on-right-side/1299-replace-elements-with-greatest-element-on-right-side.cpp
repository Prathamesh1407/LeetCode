class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int mx=-1;
        for(int i=arr.size()-1;i>=0;i--)
        {
            int temp=arr[i];
            arr[i]=mx;
            mx=max(mx,temp);
        }
        return arr;
    }
};