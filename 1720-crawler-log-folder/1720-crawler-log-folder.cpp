class Solution {
public:
    int minOperations(vector<string>& logs) {
        int distanceFromMain=0;

        for(auto val:logs)
        {
            if(val=="../" && distanceFromMain!=0) distanceFromMain--;
            else if(iswalnum(val[0])) distanceFromMain++;
        }

        return distanceFromMain;
    }
};