class Solution {
    bool topo(vector<int>adj[],int n)
    {
        vector<int> indegree(n, 0);
        vector<int> ans;
        for (int i = 0; i < n; i++) {
            for (auto it : adj[i]) {
                indegree[it]++;
            }
        }
         queue<int> qrr;
        // Initially insert elements who has
        // indegree 0
        for (int i = 0; i < n; i++) {
 
            if (indegree[i] == 0) {
                qrr.push(i);
            }
        }
 
        while (!qrr.empty()) {
            // push those elements in queue which
            // poses 0 indegree
            int node = qrr.front();
            ans.push_back(node);
            qrr.pop();
            for (auto it : adj[node]) {
                indegree[it]--;
                if (indegree[it] == 0) {
                    qrr.push(it);
                }
            }
        }
        return ans.size()==n;
    }
public:
    bool canFinish(int n, vector<vector<int>>& prerequisites) {
        stack<int>st;
        vector<int>visited(n,0);
        vector<int>adjList[n];
        for(auto val:prerequisites)
        {
            adjList[val[0]].push_back(val[1]);
        }
        
        return topo(adjList,n);
    }
};