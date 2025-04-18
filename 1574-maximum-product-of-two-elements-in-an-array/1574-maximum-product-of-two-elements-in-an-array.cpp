class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxi=0,secondLargest=0;

        for(auto val:nums)
        {
            if(val>maxi)
            {
                secondLargest=maxi;
                maxi=val;
            }

            else if(val<=maxi && val>secondLargest)
            {
                secondLargest=val;
            }
        }
        //cout<<maxi<<" "<<secondLargest;
        return (maxi-1)*(secondLargest-1);
    }
};