class Solution {
    int solve(vector<vector<int>>& books,int ind,int remainingWidth,int orgWidth,int maxHeightRow,vector<vector<int>>&dp)
    {
        if(ind>=books.size())
        {
            return maxHeightRow;
        }
        
        if(dp[ind][remainingWidth]!=-1) return dp[ind][remainingWidth];
        
        int bookWidth=books[ind][0];
        int bookHeight=books[ind][1];
        int keep,skip;
        keep=skip=INT_MAX;
        //Keep the book on shelf
        if(remainingWidth>=bookWidth)
        {
            keep=solve(books,ind+1,remainingWidth-bookWidth,orgWidth,max(maxHeightRow,bookHeight),dp);
        }
        
        //Skip the book and place it in the next shelf
        
        //As we are keeping the book in next shelf add the previous height
        skip=maxHeightRow+solve(books,ind+1,orgWidth-bookWidth,orgWidth,bookHeight,dp);
        
        return dp[ind][remainingWidth]=min(keep,skip);
    }
public:
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        //Here we will use the logic of pick or not pick and will keep the record of height
        
        vector<vector<int>>dp(1001,vector<int>(1001,-1));
        return solve(books,0,shelfWidth,shelfWidth,0,dp);
    }
};