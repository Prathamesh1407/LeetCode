class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int n=arr.size();
        /*
        vector<int>prefix(n),suffix(n);
        prefix[0]=arr[0];
        suffix[n-1]=arr[n-1];
        int maxi=arr[0],mini=arr[n-1];
        for(int i=1;i<n;i++)
        {
            prefix[i]=maxi;
            if(maxi<arr[i])
            {
                maxi=arr[i];
            }

            if(mini>arr[n-i-1])
            {
                mini=arr[n-i-1];
            }
            suffix[n-i-1]=mini;
        }

        // for(auto val:prefix) cout<<val<<" ";
        // cout<<endl;
        // for(auto val:suffix) cout<<val<<" ";
        int chunks=1;
        for(int i=0;i<n;i++)
        {
            if(prefix[i]<suffix[i]) chunks++;
        }
        return chunks;
        */

        int chunks=0,expSum=0,orgSum=0;
        for(int i=0;i<n;i++)
        {
            expSum+=arr[i];

            orgSum+=i;

            if(expSum==orgSum) chunks++;
        }
        return chunks++;
    }
};