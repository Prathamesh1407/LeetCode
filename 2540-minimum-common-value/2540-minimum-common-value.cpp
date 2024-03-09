class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        int i=0,j=0;
        while(i<=nums1.size() && j<=nums2.size())
        {
            if(nums1[i]<nums2[j])
            {
                if(i<nums1.size()-1) i++;
                else break;
            }
            else if(nums1[i]>nums2[j])
            {
                if(j<nums2.size()-1) j++;
                else break;
            }
            else return nums1[i];
        }
        return -1;
    }
};