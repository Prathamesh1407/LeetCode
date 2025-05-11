class Solution {
public:
    int minimumRecolors(string s, int k) {
        int consFreq=0,mini=INT_MAX,changes=0;
        int left=0,right=0,n=s.length();
        while(left<n && right<n)
        {
            if(s[right]=='W')
            {
                changes++;
            }
            if(right-left+1==k)
            {
                //we got our 1st k length subarray
                mini=min(mini,changes);
                if(s[left]=='W') changes--;
                left++;
            }
            right++;
        }
        //if(right-left==k) mini=min(mini,changes);
        return mini;
    }
};