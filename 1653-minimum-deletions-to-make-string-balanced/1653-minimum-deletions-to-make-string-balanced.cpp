class Solution {
public:
    int minimumDeletions(string s) {
        
        //TC : O(N)
        //SC : O(N)
        /*
        stack<char>st;
        int i=0,ans=0;
        
        for(int i=0;i<s.length();i++)
        {
            if(!st.empty() && s[i]=='a' && st.top()=='b')
            {
                st.pop();
                ans++;
            }
            else st.push(s[i]);
        }
        return ans;
        */
        
        //TC : O(N)
        //SC : O(2N)
        int n=s.length(),ans=INT_MAX;
        vector<int>rightA(n);
        vector<int>leftB(n);
        
        int countB=0;
        for(int i=0;i<n;i++)
        {
            leftB[i]=countB;
            if(s[i]=='b') countB++;
        }
        
        int countA=0;
        for(int i=n-1;i>=0;i--)
        {
            rightA[i]=countA;
            if(s[i]=='a') countA++;
        }
        
        for(int i=0;i<n;i++)
        {
            ans=min(ans,leftB[i]+rightA[i]);
        }
        return ans;
    }
};