/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    int findPos(vector<int>& post,int s,int e,int x)
    {
        for(int i=s;i<=e;i++)
        {
            if(x==post[i]) return i;
        }
        return -1;
    }
    TreeNode* solve(vector<int>& in, vector<int>& post,int &ind,int s,int e)
    {
        if(s>e || ind<0) return NULL;
        
        int element=post[ind--];
        TreeNode* root=new TreeNode(element);
        int pos=findPos(in,s,e,element);
        
        root->right=solve(in,post,ind,pos+1,e);
        root->left=solve(in,post,ind,s,pos-1);
        
        return root;
        
    }
public:
    TreeNode* buildTree(vector<int>& in, vector<int>& post) {
        int postInd=in.size()-1;
        TreeNode* ans=solve(in,post,postInd,0,postInd);
        return ans;
    }
};