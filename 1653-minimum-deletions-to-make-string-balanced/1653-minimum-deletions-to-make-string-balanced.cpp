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
        
        //TC : O(3N)
        //SC : O(2N)
        
        //What we don't want is b at the right side and a in the left side so precompute the counts and find the minimum of their addition
        
        /*
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
        */
        
        //TC : O(2N)
        //SC : O(N)
        //Instead of taking 2 vectors just take only 1 because at the 3rd loop we are starting from the start only so there is no need to precompute the B 
        
        int n=s.length(),ans=INT_MAX;
        vector<int>rightA(n);
        
        int countB=0;
        int countA=0;
        for(int i=n-1;i>=0;i--)
        {
            rightA[i]=countA;
            if(s[i]=='a') countA++;
        }
        
        for(int i=0;i<n;i++)
        {
            ans=min(ans,countB+rightA[i]);
            if(s[i]=='b') countB++;
        }
        return ans;
        
        
    }
};