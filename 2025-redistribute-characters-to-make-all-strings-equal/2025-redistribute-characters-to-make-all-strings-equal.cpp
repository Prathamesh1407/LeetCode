class Solution {
public:
    bool makeEqual(vector<string>& words) {
        vector<int>a(26,0);

        for(auto &word:words)
        {
            for(auto &val:word)
            {
                a[val-'a']++;
            }
        }

        for(int i=0;i<26;i++)
        {
            if(a[i]%words.size()!=0) return 0;
        }
        return 1;
    }
};