class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        //TC : O(2N)
        //SC : O(1) we are storing only 2 or 3 elements at a time so we can consider it as 1
        
        int left=0,right=0,res=0;
        unordered_map<int,int>m;//{element,frequency}
        while(right<fruits.size())
        {
            m[fruits[right]]++;
            
            while(m.size()>2)
            {
                m[fruits[left]]--;
                if(m[fruits[left]]==0) m.erase(fruits[left]);
                left++;
            }
            
            res=max(res,right-left+1);
            right++;
        }
        
        return res;
    }
};