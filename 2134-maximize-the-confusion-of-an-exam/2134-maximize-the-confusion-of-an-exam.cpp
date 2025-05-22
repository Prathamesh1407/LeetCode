class Solution {
public:
    int maxConsecutiveAnswers(string s, int k) {
        int maxi=0;
        int i=0,j=0;
        unordered_map<char,int>m;
        while(j<s.length())
        {
            m[s[j]]++; 

            while(min(m['T'],m['F'])>k)
            {
                m[s[i]]--;
                i++;
            }
            maxi=max(maxi,j-i+1);
            j++;
        }
        return maxi;
    }
};