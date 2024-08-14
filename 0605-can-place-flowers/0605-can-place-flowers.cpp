class Solution {
public:
    bool canPlaceFlowers(vector<int>& v ,int k) {
        int n=v.size();
            
        if(k==0) return 1;
        
        for(int i=0;i<n;i++)
        {
            if(v[i]==0)
            {
                bool leftVacant=(i==0 || v[i-1]==0);
                bool rightVacant=(i==n-1 || v[i+1]==0);

                if(leftVacant && rightVacant) 
                {
                    k--;
                    if(k==0) return 1;
                    v[i]=1;
                }
            }
            
        }
        return 0;
    }
};