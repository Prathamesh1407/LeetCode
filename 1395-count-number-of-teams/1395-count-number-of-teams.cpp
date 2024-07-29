//TC : O(N^2)
//SC : O(1)

class Solution {
public:
    int numTeams(vector<int>& rating) {
        
        int n=rating.size(),ans=0;
        
        for(int j=1;j<n-1;j++)
        {
            int countSmallerRight=0,countSmallerLeft=0;
            int countLargerRight=0,countLargerLeft=0;
            
            //Left Side
            for(int i=0;i<j;i++)
            {
                if(rating[i]<rating[j])
                {
                    countSmallerLeft++;
                }
                else if(rating[i]>rating[j])
                {
                    countLargerLeft++;
                }
            }
            
            //Right Side
            for(int i=j+1;i<n;i++)
            {
                if(rating[i]<rating[j])
                {
                    countSmallerRight++;
                }
                else if(rating[i]>rating[j])
                {
                    countLargerRight++;
                }
            }
            
            //Ascending * Descending
            ans+=(countSmallerLeft*countLargerRight) + (countLargerLeft*countSmallerRight);
            
        }
        return ans;
    }
};