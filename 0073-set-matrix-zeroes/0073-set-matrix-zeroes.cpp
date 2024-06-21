class Solution {
public:
    void setZeroes(vector<vector<int>>& a) {
        int col0=1;
        int n=a.size(),m=a[0].size();
        //Here we are keep tracking of 0's in given matrix only in 0th row and 0th col but (0,0) will overlap so we will take one variable to represent col1 
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(a[i][j]==0)
                {
                    //mark the ith row
                    a[i][0]=0;
                    //mark the jth row
                    if(j!=0)
                    {
                        a[0][j]=0;
                    }
                    else col0=0;
                }
            }
        }
        
        //now change the array elements according to 0th row and 0th col so first start iterating from 1st row and 1st col to avoid (0,0) field
        
        for(int i=1;i<n;i++)
        {
            for(int j=1;j<m;j++)
            {
                if(a[i][j]!=0)
                {
                    if(a[0][j]==0 || a[i][0]==0) a[i][j]=0;    
                }
            }
        }
        
        //for (0,0) field the 0th row and 0th col depends on it if we change change the 0th col , but the 0th row depends on it so first change the 0th row and then with the help of col0 change 0th col
        if(a[0][0]==0)
        {
            for(int j=0;j<m;j++)
            {
                a[0][j]=0;  
            }    
        }
        if(col0==0)
        {
            for(int i=0;i<n;i++)
            {
                a[i][0]=0;
            }
        } 
    }
};