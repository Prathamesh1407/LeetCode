class Solution {
    bool isVowel(char ch)
    {
        if(ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u') return 1;
        return 0;
    }
public:
    int maxVowels(string s, int k) {
        int vowel=0;

        int i=0,j=0,ans=0;

        while(j<s.length())
        {
            if(isVowel(s[j])) vowel++;
            if(j-i+1==k)
            {
                ans=max(ans,vowel);
                if(isVowel(s[i])) vowel--;
                i++;
            }
            j++;
        }
        return ans;
    }
};