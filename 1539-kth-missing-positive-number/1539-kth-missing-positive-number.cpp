class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int p=1;
        for(int i=0;i<arr.size();)
        {
            if(arr[i]!=p)
            {
                //cout<<i<<" ";
                k--;
                if(k==0) return p;
            }
            else i++;
            p++;
        }
       
            return arr[arr.size()-1]+k;
        
    }
};