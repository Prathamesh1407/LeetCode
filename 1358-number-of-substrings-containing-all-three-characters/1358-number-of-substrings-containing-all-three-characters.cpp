//TC : O(N)
//SC : O(1)
class Solution {
public:
    int numberOfSubstrings(string s) {
        
        //bbacba 
        //here we will keep updating the index of 3 letters b=1 b=2 a=2 c=3 , as all are found find the least index letter that is a=2 now the substring is bbacb just add the a=2 +1 i.e 3 substring will be created bbacb bacb acb just like traverse the whole string
        
        vector<int>v(3,-1);
        int res=0;
        for(int i=0;i<s.length();i++)
        {
            v[s[i]-'a']=i;
            
            if(v[0]!=-1 && v[1]!=-1 && v[2]!=-1)
            {
                res+=min(v[0],min(v[1],v[2]))+1;
            }
        }
        return res;
    }
};