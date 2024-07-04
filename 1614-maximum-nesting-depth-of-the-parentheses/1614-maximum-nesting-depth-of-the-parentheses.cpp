class Solution {
public:
    int maxDepth(string s) {
        int c=0,maxi=0;
        for(auto val:s)
        {
            if(val=='(') c++;
            else if(val==')') c--;
            maxi=max(maxi,c);
        }
        return maxi;
    }
};