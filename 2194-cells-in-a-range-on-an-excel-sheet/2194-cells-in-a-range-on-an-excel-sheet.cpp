class Solution {
public:
    vector<string> cellsInRange(string s) {
        vector<string>ans;
        char startingLetter=s[0];
        char endingLetter=s[3];
        
        char sCol=s[1],eCol=s[4];
        for(char i=startingLetter;i<=endingLetter;i++)
        {
            for(char j=sCol;j<=eCol;j++)
            {
                string temp;
                temp.push_back(i);
                temp.push_back(j);
                ans.push_back(temp);
            }
        }
        return ans;
    }
};