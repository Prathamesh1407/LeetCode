class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int threshold) {
        vector<vector<int>>matrix(n,vector<int>(n,INT_MAX));
        
        for(auto val:edges)
        {
            //Undirected u v w and v u w
            matrix[val[0]][val[1]]=val[2];
            matrix[val[1]][val[0]]=val[2];
        }
        for(int i=0;i<n;i++) matrix[i][i]=0;
        for(int via=0;via<n;via++)
        {
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<n;j++)
                {
                    //from i => j via 0 => n
                    // if i -> j via 0 then i -> 0 then 0 -> j
                    if(matrix[i][via]==INT_MAX || matrix[via][j]==INT_MAX) continue;
                    matrix[i][j]=min(matrix[i][j],matrix[i][via]+matrix[via][j]);
                }
            }
        }
        
        int cityNo=-1,cntCity=n;
        
        for(int city=0;city<n;city++)
        {
            int c=0;
            for(int j=0;j<n;j++)
            {
                if(matrix[city][j]<=threshold) c++;
            }
            if(cntCity>=c)
            {
                cntCity=c;
                cityNo=city;
            }
        }
        return cityNo;
    }
};