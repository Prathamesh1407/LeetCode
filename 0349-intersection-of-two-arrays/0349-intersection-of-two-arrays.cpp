class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        /*
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());
        
        vector<int>ans;
        unordered_set<int>s;
        
        int i=0,j=0;
        while(i<nums1.size() && j<nums2.size())
        {
            if(nums1[i]==nums2[j])
            {
                s.insert(nums1[i]);
                i++;
                j++;
            }
            else if(nums1[i]<nums2[j]) i++;
            else j++;
        }
        
        for(auto val:s) ans.push_back(val);
        return ans;
        */

        //A2: Traverse ans skip for the same element so we won't be needing set

        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());
        
        vector<int>ans;
        int n=nums1.size(),m=nums2.size();
        int i=0,j=0;
        while(i<nums1.size() && j<nums2.size())
        {
            if(nums1[i]==nums2[j])
            {
                ans.push_back(nums1[i]);
                while(i<n-1 && nums1[i]==nums1[i+1]) i++;
                while(j<m-1 && nums2[j]==nums2[j+1]) j++;
                i++;
                j++;
            }
            else if(nums1[i]<nums2[j]) i++;
            else j++;
        }
        return ans;



    }
};