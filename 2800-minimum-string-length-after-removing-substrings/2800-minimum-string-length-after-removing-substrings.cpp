class Solution {
public:
    int minLength(string st) {
        //A1: TC:O(n) SC: O(n) Use Stack

        stack<char>s;

        for(auto val:st)
        {
            if(s.empty()) s.push(val);
            else if(val=='D' && s.top()=='C') s.pop();
            else if(val=='B' && s.top()=='A') s.pop();
            else s.push(val);
        }
        return s.size();
    }
};