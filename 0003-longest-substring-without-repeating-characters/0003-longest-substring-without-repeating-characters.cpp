class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        
        //A1:
        //TC : O(2*N) sometimes when element existed in substring already it has to traversed to that next existing element
        //SC : O(1)
        /*
        unordered_set<char>st;
        int left=0,right=0,res=0;
        while(right<s.length())
        {
            while(st.find(s[right])!=st.end())
            {
                st.erase(s[left]);
                left++;
            }
            st.insert(s[right]);
            res=max(res,right-left+1);
            right++;
        }
        return res;
        */
        
        //A2
        //TC : O(2*N) sometimes when element existed in substring already it has to traversed to that next existing element
        //SC : O(1)
        
        vector<int>v(256,-1);
        
        int left=0,right=0,res=0,n=s.length();
        
        while(right<n)
        {
            if(v[s[right]]!=-1)
            {
                if(v[s[right]]>=left)
                {
                    //Means present in the current substring not the previous one then bring that left pointer to that previously existing index + 1
                    left=v[s[right]]+1;
                    //cout<<left<<" ";
                }
            }
            
            res=max(res,right-left+1);
            v[s[right]]=right;
            right++;
        }
        return res;
        
    }
};