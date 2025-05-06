class Solution {
public:
    string makeFancyString(string s) {
        string ans;
        ans.push_back(s[0]);

        int freq=1;

        for(int i=1;i<s.length();i++)
        {
            if(ans.back()==s[i])
            {
                freq++;
            }
            else
            {
                freq=1;
            }
            if(freq==3) 
            {
                freq--;
                continue;
            }
            ans.push_back(s[i]);
        }
        return ans;
    }
};