class Solution {
    bool checkRotation(string& s, string& goal,int rotation)
    {
        int n=goal.length();
        for(int i=0;i<s.length();i++)
        {
            if(s[i]!=goal[(rotation+i)%n]) return false;
        }
        return true;
    }
public:
    bool rotateString(string s, string goal) {
        
        //TC : O(N*M) as N is the length of string and M is the substring that we wanted to find
        //SC : O(1)
        //A1:
        /*
        if(s.length()!=goal.length()) return false;
        s=s+s;
        //if s= "abcde" s=> "abcdeabcde"
        return s.find(goal)!=string::npos;
        */
        
        //TC : O(N*M) as N is the length of string and M is the substring that we wanted to find
        //SC : O(1)
        //A2:
        
        if(s.length()!=goal.length()) return false;
        for(int i=0;i<s.length();i++)
        {
            if(checkRotation(s,goal,i)) return true;
        }
        return false;
        
    }
};