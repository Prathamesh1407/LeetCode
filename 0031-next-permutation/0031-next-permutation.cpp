//T.C : O(3N)
//S.C : O(1)
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n=nums.size(),ind=-1;
        //check for the peak element index eg 2 1 | 5 4 3 0 0 here it will be 1
        for(int i=n-2;i>=0;i--)
        {
            if(nums[i]<nums[i+1])
            {
                ind=i;
                break;
            }
        }
        //if we haven't got the index means this is the last permutation so reverse and return eg 5 4 3 2 1 0 0
        if(ind==-1) 
        {
            reverse(nums.begin(),nums.end());
            return;
        }
        //Means we got a index,now we want our array to be greater but in a closest way so find a element just greater than index element and swap with it.
        
        //Keep in mind we find the index at the peak means all the left side is sorted in a descending order that's why to find just greater we are starting from end
        for(int i=n-1;i>ind;i--)
        {
            if(nums[i]>nums[ind]) 
            {
                swap(nums[i],nums[ind]);
                break;
            }
        }
        //Now the left side is became greater so we want our left side to be the smallest possible that's why reverse it 
        reverse(nums.begin()+ind+1,nums.end());
    }
};