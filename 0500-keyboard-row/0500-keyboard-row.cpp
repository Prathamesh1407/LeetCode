class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        unordered_map<char,int>m;
        vector<string>ans;
        string a="qwertyuiop",b="asdfghjkl",c="zxcvbnm";
        for(auto val:a)
        {
            m[val]=1;
        }
        for(auto val:b)
        {
            m[val]=2;
        }
        for(auto val:c)
        {
            m[val]=3;
        }

        for(auto &word:words)
        {
            int lastLevel=0,flag=0;
            for(auto &val:word)
            {
                if(lastLevel==0) lastLevel=m[tolower(val)];
                else
                {
                    if(m[tolower(val)]!=lastLevel) 
                    {
                        flag=1;
                        break;
                    }
                }
            }
            if(flag==0) ans.push_back(word);
        }

        return ans;
    }
};