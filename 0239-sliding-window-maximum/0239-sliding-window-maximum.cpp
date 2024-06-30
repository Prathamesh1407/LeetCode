//TC : O(N+N)
//SC : O(k)
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int>deq;
        vector<int>ans;
        for(int i=0;i<nums.size();i++)
        {
            //Step 1 : Check for Window is it out of bound of our K so it will be of i-k , <i-k all will be out of bound
            while(deq.empty()==false && deq.front()<=i-k) deq.pop_front();

            //Step 2 : Now the out of bound elements are gone , now we maintain the deque in decreasing order
            while(deq.empty()==false && nums[deq.back()]<nums[i]) deq.pop_back();


            //Step 4: Now all the Small elements will be deleted than nums[i] now the maximum element of window will be present at front
            deq.push_back(i);

            if(i>=k-1)
            {
                ans.push_back(nums[deq.front()]);
            }   
        }
        return ans;
        
    }
};