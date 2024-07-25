class Solution {
public:
    int characterReplacement(string s, int k) {
        //Lets generate all the substrings length of substring - maxfreq element in that substring will tell us how many letters we can change
        int n=s.length(),res=0;
        for(int i=0;i<n;i++)
        {
            vector<int>v(26,0);
            int maxFreq=0;
            for(int j=i;j<n;j++)
            {
                v[s[j]-'A']++;
                maxFreq=max(v[s[j]-'A'],maxFreq);
                
                //how many diffrent letters in the substring than maxFreq
                
                int changes=(j-i+1)-maxFreq;
                
                if(changes<=k)
                {
                    //we can update the max length
                    res=max(res,j-i+1);
                }
                else break; //Means there are more than K diffrent letters
                
            }
        }
        return res;
    }
};