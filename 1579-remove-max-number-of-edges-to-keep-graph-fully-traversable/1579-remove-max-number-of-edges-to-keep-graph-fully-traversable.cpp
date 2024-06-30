class DSU
{
    public:
    vector<int>parent,rank;
    int components;
    DSU (int n)
    {
        parent.resize(n+1);
        rank.resize(n+1);
        for (int i = 1; i <=n; i++)
        {
            parent[i] = i;
            rank[i] = 0;
        }
        components=n;
    }

    int findParent(int node)
    {
        if (parent[node] == node)
            return node;
        //parent[node]= is for the path compression
        return parent[node] = findParent(parent[node]);
    }

    void unionSet(int u, int v)
    {
        u = findParent(u);
        v = findParent(v);

        if (rank[u] < rank[v])
        {
            parent[u] = v;
        }
        else if (rank[u] > rank[v])
        {
            parent[v] = u;
        }
        else
        {
            // can make any node parent of other node and upgrade the rank of the parent node
            parent[v] = u;
            rank[u]++;
        }
        components--;
    }
    
    bool isSingleComponent()
    {
        return components==1;
    }
};

class Solution {
    static bool compare(vector<int>&a,vector<int>&b)
    {
        return a[0]>b[0];
    }
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        
        DSU Alice(n);
        DSU Bob(n);
        sort(edges.begin(),edges.end(),compare);
        int edgesCount=0;
        for(auto val:edges)
        {
            int type=val[0];
            int u=val[1];
            int v=val[2];
            bool isAgeAdded=0;
            if(type==3)
            {
                if(Alice.findParent(u)!=Alice.findParent(v))
                {
                    Alice.unionSet(u,v);
                    isAgeAdded=1;
                }
                if(Bob.findParent(u)!=Bob.findParent(v))
                {
                    Bob.unionSet(u,v);
                    isAgeAdded=1;
                }
                edgesCount+=isAgeAdded;
            }
            else if(type==2)
            {
                if(Bob.findParent(u)!=Bob.findParent(v))
                {
                    Bob.unionSet(u,v);
                    edgesCount++;
                }
            }
            else if(type==1)
            {
                if(Alice.findParent(u)!=Alice.findParent(v))
                {
                    Alice.unionSet(u,v);
                    edgesCount++;
                }
            }
        }
        if(Alice.isSingleComponent()==1 && Bob.isSingleComponent()==1)
        {
            return edges.size()-edgesCount;
        }
        return -1;
    }
};