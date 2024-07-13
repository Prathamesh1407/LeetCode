class Solution {
public:
    int search(vector<int>& nums, int target) {
        //A1:Linear Search
        
        //A2: Binary Search
        //Either one portion will be sorted left or right so check the target is in the left and mid or mid and right
        
        int low=0,high=nums.size()-1,mid;
        
        while(low<=high)
        {
            mid=low + (high-low)/2;
            if(nums[mid]==target) return mid;
            
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
        return -1;
    }
};