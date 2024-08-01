class Solution {
public:
    int titleToNumber(string s) {
        long long n=s.length(),ans=0;
        //A->Z 26 AB whole 26 + 1 27 A B->z => BA means 2 traversal of 26 and 1 A : 53
        for(int i=0;i<n-1;i++)
        {
            ans+=(pow(26,n-i-1)*(s[i]-'A'+1));
            //cout<<s[i]-'A'+1<<" ";
        }
        ans+=s[n-1]-'A'+1;
        return ans;
    }
};