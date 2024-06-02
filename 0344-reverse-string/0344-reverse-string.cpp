class Solution {
public:
    void reverseString(vector<char>& s) {
        int a=0,e=s.size()-1;
        while(a<e)
        {
            char temp=s[a];
            s[a]=s[e];
            s[e]=temp;
            a++; e--;
        }
    }
};