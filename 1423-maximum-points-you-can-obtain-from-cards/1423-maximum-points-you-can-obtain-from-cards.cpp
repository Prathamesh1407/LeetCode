//TC : O(2*K)
//SC : O(1)

class Solution {
public:
    int maxScore(vector<int>& card, int k) {
        //take the example as 6 2 3 4 7 2 1 7 1 first calculate first k element and after reduce 1 element from left and add the rightmost 1 element in rsum keep doing that
        int n=card.size();
        int lsum=0,rsum=0,ans=0;
        
        for(int i=0;i<k;i++)
        {
            lsum+=card[i];
        }
        ans=lsum;
        int rIndex=n-1;
        for(int i=k-1;i>=0;i--)
        {
            lsum-=card[i];
            rsum+=card[rIndex];
            rIndex--;
            ans=max(ans,lsum+rsum); 
        }
        return ans;
    }
};