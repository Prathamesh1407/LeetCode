class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        int n=words.size();
        vector<int>v(26,INT_MAX);
        vector<string>ans;
        for(auto &word:words)
        {
            vector<int>temp(26,0);
            for(auto &val:word)
            {
                temp[val-'a']++;
            }
            for(int i=0;i<26;i++)
            {
                v[i]=min(temp[i],v[i]);
            }
        }

        for(int i=0;i<26;i++) 
        {
            ans.insert(ans.end(),v[i],string(1,'a'+i));
        }
        return ans;
    }
};