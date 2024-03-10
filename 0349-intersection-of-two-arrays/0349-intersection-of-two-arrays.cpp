class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
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
    }
};