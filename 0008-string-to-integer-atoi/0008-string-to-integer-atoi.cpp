class Solution {
public:
    int myAtoi(string s) {
        if(s.length()==0) return 0;
        long result=0;
        int indicator=1;
        int j=0,n=s.length();
        while(j<n && s[j]==' ') j++;
        
        for(int i=j;i<n;i++)
        {
            if(s[i]=='-' || s[i]=='+') 
            {
                if(s[i]=='-') indicator=-1;
                i++;
            }
            while(i<n && isdigit(s[i]))
            {    
                result=result*10 + (s[i]-'0');
                if(result*indicator<INT_MIN) return INT_MIN;
                else if(result*indicator>INT_MAX) return INT_MAX;
                i++;
            }
            return result*indicator;
        }
        return 0;
    }
};