class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.length()!=goal.length()) return false;
        s=s+s;
        //if s= "abcde" s=> "abcdeabcde"
        return s.find(goal)!=string::npos;
    }
};