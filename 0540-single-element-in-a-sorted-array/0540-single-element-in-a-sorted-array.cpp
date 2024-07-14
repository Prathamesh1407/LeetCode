class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        //Lets take a case of 1 1 2 3 3 now 1 1 is on even odd index so they are on the left side and the single element present on the right portion of it but 3 3 is on odd even index means right side and the single element present on the left portion of it
        
        //We will handle the first two numbers and last 2 to avoid further index bound condition
        if(nums.size()==1) return nums[0];
        
        int n=nums.size();
        if(nums[0]!=nums[1]) return nums[0];
        if(nums[n-1]!=nums[n-2]) return nums[n-1];
            
        int low=0,high=nums.size()-1;
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            if(nums[mid]!=nums[mid-1] && nums[mid]!=nums[mid+1])
            {
                //Unique Element
                return nums[mid];
            }
            //Now the odd even logic
            // (even,odd) => Left portion , eliminate the left part 
            // (odd,even) => Right portion , eliminate the right part
            
            //Left Portion
            if( ((mid&1) && nums[mid]==nums[mid-1]) || (!(mid&1) && nums[mid]==nums[mid+1]) )
            {
                //eliminate the left part
                low=mid+1;
            }
            //Right Portion
            else
            {
                high=mid-1;
            } 
        }
        return -1;
    }
};