class Solution {
public:
    int characterReplacement(string s, int k) {
        //Lets generate all the substrings length of substring - maxfreq element in that substring will tell us how many letters we can change
        //TC : O(N^2)
        //SC : O(26)
        /*
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
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
        */
        
        //Sliding Window Technique
        
        int left=0,right=0,res=0,maxFreq=0;
        unordered_map<int,int>m;
        while(right<s.length())
        {
            m[s[right]-'A']++;
            
            maxFreq=max(maxFreq,m[s[right]-'A']);
            
            //The substring contains more than K diffrent
            while((right-left+1)-maxFreq>k)
            {
                m[s[left]-'A']--;
                maxFreq=0;
                //Update the maxFreq After removing letter
                for(auto val:m)
                {
                    maxFreq=max(maxFreq,val.second);
                }
                left++;
            }
            res=max(res,right-left+1);
            right++;
        }
        return res;
    }
};