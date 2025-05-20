class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int>m;

        for(auto val:t) m[val]++;

        int startInd=-1,countRequired=t.length();
        int i=0,j=0,mini=INT_MAX;
        while(j<s.length())
        {
            if(m[s[j]]>0) 
            {
                countRequired--;
            }
            m[s[j]]--;

            while(countRequired==0)
            {
                if(j-i+1<mini)
                {
                    mini=j-i+1;
                    startInd=i;
                }
                m[s[i]]++;
                if(m[s[i]]>0) countRequired++;
                i++;
            }
            j++;
        }
        return mini == INT_MAX ? "" : s.substr(startInd, mini);

    }
};