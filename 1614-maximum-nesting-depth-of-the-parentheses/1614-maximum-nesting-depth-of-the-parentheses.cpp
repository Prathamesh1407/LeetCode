class Solution {
public:
    int maxDepth(string s) {
        //TC : O(N)
        int c=0,maxi=0;
        for(auto val:s)
        {
            if(val=='(') c++;
            else if(val==')') c--;
            maxi=max(maxi,c);
        }
        return maxi;
        
        //Another approach can be using stack if ( push in the stack and if ) check the stack size and keep updating max by size
    }
};