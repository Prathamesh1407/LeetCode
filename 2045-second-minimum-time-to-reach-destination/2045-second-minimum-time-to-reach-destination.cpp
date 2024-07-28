class Solution {
public:
    int secondMinimum(int n, vector<vector<int>>& edges, int time, int change) {
        
        //BFS : Level order Traversal
        
        unordered_map<int,vector<int>>adjList;
        for(auto val:edges)
        {
            //Bi-directional
            adjList[val[0]].push_back(val[1]);
            adjList[val[1]].push_back(val[0]);
        }
        vector<int>min1(n+1,INT_MAX);
        vector<int>min2(n+1,INT_MAX);
        queue<pair<int,int>>q; //Node,freq of traversing
        
        q.push({1,1});
        min1[1]=0; //Distance from source of source is 0
        while(!q.empty())
        {
            auto frontNode=q.front();
            q.pop();
            
            int node=frontNode.first;
            int freq=frontNode.second;
            
            //If node == n and min2[node] is valid means we have got the second minimum distance till last node because further running the loop will increase the distance
            if(node==n && min2[node]!=INT_MAX) return min2[node];
            
            
            int timePassed=(freq==1?min1[node]:min2[node]);
            
            //if timePassed is 6 then the light is red or green how to indentify then 6/5 = 1 that is odd means at the red light , then when will it be green so just add 1 (1+1)*change i.e 10
            int divisions=timePassed/change;
            
            if(divisions%2==1)
            {
                //Odd : Red
                timePassed=change*(divisions+1);
            }
            
            for(auto nbr:adjList[node])
            {
                if(min1[nbr]==INT_MAX)
                {
                    //means 1st minimum coz we are applying BFS
                    
                    //Previous Time Passed + the time to travel a edge
                    min1[nbr]=timePassed+time;
                    q.push({nbr,1});
                }
                else if(min2[nbr]==INT_MAX && min1[nbr]!=timePassed+time)
                {
                    //means 2nd minimum
                    min2[nbr]=timePassed+time;
                    q.push({nbr,2});
                }
            }
        }
        return -1;
    }
};