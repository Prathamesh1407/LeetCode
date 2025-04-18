class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        vector<int>charCount(26,0);
        int ans=0;
        for(auto val:chars)
        {
            charCount[val-'a']++;
        }

        for(auto &word:words)
        {
            vector<int>wordCount(26,0);
            for(auto &val:word)
            {
                wordCount[val-'a']++;
            }

            int flag=0;
            for(int i=0;i<26;i++)
            {
                if(charCount[i]<wordCount[i])
                {
                    flag=1;
                    break;
                }
            }

            if(!flag) ans+=word.length();
        }

        return ans;
    }
};