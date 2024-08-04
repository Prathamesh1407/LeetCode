class Solution {
public:
    bool search(vector<int>& nums, int target) {
        //A1:Linear Search
        
        //A2: Binary Search
        
        //Let's take a array 1 0 1 1 1 mid will be 2 but nums low = high=mid so just reduce the search space by 1 low ++ high -- and apply the same logic of 1 Q so you could be able to find the true sorted portion
        
        int low=0,high=nums.size()-1,mid;
        
        while(low<=high)
        {
            mid=low + (high-low)/2;
            if(nums[mid]==target) return 1;
            if(nums[mid]==nums[low] && nums[mid]==nums[high]) 
            {
                low++;
                high--;
                continue;
            }
            //Left Sorted
            if(nums[low]<=nums[mid])
            {
                //Check if the element lies between them
                if(nums[low]<=target && nums[mid]>=target) 
                {
                    //If target lies between left bring high on mid-1 (left side)
                    high=mid-1;
                }
                else
                {
                    //If target does not lie take the low on right side mid+1
                    low=mid+1;
                }
            }
            //Right Sorted
            else
            {
                if(nums[mid]<=target && nums[high]>=target)
                {
                    low=mid+1;
                }
                else 
                {
                    high=mid-1;
                }
            }  
        }
        return 0;
    }
};
