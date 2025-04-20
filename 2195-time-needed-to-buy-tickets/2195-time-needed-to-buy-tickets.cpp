class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int ele=tickets[k],ans=0;

        for(int i=0;i<tickets.size();i++)
        {
            if(i<=k)
            {
                if(tickets[i]<=ele)
                {
                    ans+=tickets[i];
                } 
                else
                {
                    ans+=ele;
                }
            }
            else
            {
                if(tickets[i]>=ele) ans+=ele-1;
                else ans+=tickets[i];
            }
        }
        return ans;
    }
};