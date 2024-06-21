//TC : O(N log N) to sort + O(N2)
//SC : O(1)
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& a) {
        vector<vector<int>>ans;
        int n=a.size();
        sort(a.begin(),a.end());
        for(int i=0;i<n;i++)
        {
            //if i is same as before no need to traverse it from again, same for j and k 
            if(i>0 && a[i]==a[i-1]) continue;
            int j=i+1;
            int k=n-1;
            while(j<k)
            {
                int sum=a[i]+a[j]+a[k];
                if(sum<0)
                {
                    j++;
                }
                else if(sum>0)
                {
                    k--;
                }
                else
                {
                    vector<int>temp={a[i],a[j],a[k]};
                    ans.push_back(temp);
                    j++;
                    k--;
                    while(j<k && a[j]==a[j-1]) j++;
                    while(j<k && a[k]==a[k+1]) k--;
                }
            }
        }
        return ans;
    }
};