class Node
{
    public:
    int data,i,j;
    
    Node(int a,int b,int c)
    {
        data=a;
        i=b;
        j=c;
    }
};
class compare
{
    public:
    bool operator()(Node* a,Node* b)
    {
        return a->data>b->data;
    }
};
class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        vector<int>ans;
        priority_queue<Node*,vector<Node*>,compare>pq;
        int maxi=INT_MIN,mini=INT_MAX;
        for(int i=0;i<nums.size();i++)
        {
            pq.push(new Node(nums[i][0],i,0));
            maxi=max(maxi,nums[i][0]);
            mini=min(mini,nums[i][0]);
        }
        int start=mini,end=maxi;
        while(!pq.empty())
        {
            Node* temp=pq.top();
            mini=temp->data;
            pq.pop();
            if(maxi-mini<end-start)
            {
                start=mini;
                end=maxi;
            }
            
            int i=temp->i,j=temp->j;
            if(j+1<nums[i].size())
            {
                maxi=max(maxi,nums[i][j+1]);
                pq.push(new Node(nums[i][j+1],i,j+1));
            }
            else break;
        }
        ans.push_back(start);
        ans.push_back(end);
        return ans;
    }
};