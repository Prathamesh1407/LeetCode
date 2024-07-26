class Solution {
public:
    string minWindow(string s, string t) {
        //TC: O(N^2)
        //SC : O(256)
        /*
        int minLength=INT_MAX,startingIndex=-1;
        for(int i=0;i<s.length();i++)
        {
            unordered_map<char,int>m;
            
            for(auto val:t) m[val]++;
            int cnt=0;
            for(int j=i;j<s.length();j++)
            {
                if(m[s[j]]>0) cnt++;
                m[s[j]]--;
                if(cnt==t.length())
                {
                    //All letters are traversed
                    if(j-i+1<minLength)
                    {
                        minLength=j-i+1;
                        startingIndex=i;
                        //cout<<startingIndex<<" ";
                        break;
                    }
                }
            }
        }
        if(minLength==INT_MAX) return "";
        string ans=s.substr(startingIndex,minLength);
        return ans;
        */
        
        
        //TC : O(2*N + M)
        //SC : O(256)
        int left=0,right=0,minLength=INT_MAX,sInd=-1;
        
        unordered_map<char,int>m;
        for(auto val:t) m[val]++;
        int cnt=0;
        while(right<s.length())
        {
            if(m[s[right]]>0)
            {
                //Means present in map means present in the t also
                cnt++;
            }
            m[s[right]]--;
            while(cnt==t.length())
            {
                //We got all the letters of t in s
                if(right-left+1<minLength)
                {
                    minLength=right-left+1;
                    sInd=left;
                }
                
                //Traverse for the minimum
                m[s[left]]++; //We are removing it from window so ++ so if aabc the count of a in map was -1 but after removing 1 a from window will do it as a -1+1=0 means still all the letters are present
                
                if(m[s[left]]>0) cnt--; //Means positive so the window does not contains that letter of t
                left++;
            }
            right++;
        }
        
        return sInd==-1 ? "":s.substr(sInd,minLength);
    }
};
