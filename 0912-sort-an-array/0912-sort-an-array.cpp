//TC : O(N*logN) At each step, we divide the whole array, for that logn and we assume n steps are taken to get sorted array, so overall time complexity will be nlogn

//SC : O(N) for temp
class Solution {
    
    void merge(vector<int>& nums,int low,int mid,int high)
    {
        //Now we have 2 arrays to merge low to mid and mid+1 to high
        
        int left=low,right=mid+1;
        vector<int>temp;
        while(left<=mid && right<=high)
        {
            if(nums[left]<=nums[right])
            {
                temp.push_back(nums[left++]);
            }
            else
            {
                temp.push_back(nums[right++]);
            }
        }
        
        while(left<=mid)
        {
            temp.push_back(nums[left++]);
        }
        
        while(right<=high)
        {
            temp.push_back(nums[right++]);
        }
        
        //Now the arrays are merged we have to update them in original array
        
        for(int i=low;i<=high;i++)
        {
            nums[i]=temp[i-low];
        }
    }
    
    void mergeSort(vector<int>& nums,int low,int high)
    {
        if(low==high) return; //Already Sorted
        
        int mid=(low+high)/2;
        
        mergeSort(nums,low,mid);
        mergeSort(nums,mid+1,high);
        
        merge(nums,low,mid,high);   
    }
public:
    vector<int> sortArray(vector<int>& nums) {
        mergeSort(nums,0,nums.size()-1);
        return nums;
    }
};