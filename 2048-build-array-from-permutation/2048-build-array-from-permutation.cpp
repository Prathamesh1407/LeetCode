class Solution {
public:
    vector<int> buildArray(vector<int>& nums) {
        /*
            nums = [5,0,1,2,3,4] Take this Eg.

            ans = [4,5,0,1,2,3] 
            [nums[nums[5]],nums[nums[0]],...]
            [4,4] this is wrong due to swapping of number previously so while changing we have to keep a track of 4 and 5 both the number as old and new 
            while changing we'll be careful and will use some mathematical trick

            now nums[nums[5]]=4 previous it was 5 and later as we changed it to 4 we'll keep a track of 4 and 5 too

            5 + some big number that won't be in the array*4

            here in the array 1 to n-1 number will be there so we will use n

            old+new*n
            eg. 5+100*4=405
            ans=405
            but how will we decode it
            old=ans%n
            new=ans/n
        */

        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            int newNum=nums[nums[i]];
            int old=nums[i];
            nums[i]=old+(newNum%n)*n;
        }
        for(int i=0;i<nums.size();i++)
        {
            nums[i]/=n;
        }
        return nums;
    }
};