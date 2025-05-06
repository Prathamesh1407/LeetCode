class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        //TC: O(n + words.size()*Avg length of words) SC:O(1)
        vector<int>v(26,0);
        int ans=0;
        for(auto val:allowed) v[val-'a']++;

        for(auto &word:words)
        {
            int flag=0;
            for(auto &ch:word)
            {
                if(v[ch-'a']==0) 
                {
                    flag=1;
                    break;
                }
            }
            if(flag==0) ans++;
        }
        return ans;
    }
};