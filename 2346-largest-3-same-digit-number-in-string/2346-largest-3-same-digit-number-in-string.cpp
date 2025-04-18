class Solution {
public:
    string largestGoodInteger(string num) {
        int ans=INT_MIN;
        for(int i=1;i<=num.length()-2;i++)
        {
            string temp="";
            if(num[i]==num[i-1] && num[i]==num[i+1])
            {
                ans=max(num[i]-'0',ans);
            }
        }

        return ans!=INT_MIN?string(3,(char)ans+'0'):"";
    }
};