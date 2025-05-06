class Solution {
public:
    int minLength(string st) {
        //A1: TC:O(n) SC: O(n) Use Stack
        /*
        stack<char>s;

        for(auto val:st)
        {
            if(s.empty()) s.push(val);
            else if(val=='D' && s.top()=='C') s.pop();
            else if(val=='B' && s.top()=='A') s.pop();
            else s.push(val);
        }
        return s.size();
        */

        //A2: TC: O(n) SC:O(1) keep the 2 pointers i and j for writing and traversing resp. i will store the letters which are not AB or CD and between them so value of i will be our answer as length and j to check C and D

        int i=0,j=1;
        string s=st;
        int n=s.length();
        while(j<n)
        {
            if(i<0)
            {
                //if its get -1 write whatever j has
                i++;
                s[i]=s[j];
            }
            else if((s[i]=='A' && s[j]=='B') || (s[i]=='C' && s[j]=='D'))
            {
                //Do not want that
                i--;
            }
            else
            {
                i++;
                s[i]=s[j];
            }
            j++;
        }
        return i+1;
    }
};