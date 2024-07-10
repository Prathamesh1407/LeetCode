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
    TreeNode* solve(vector<int>&pre,int mini,int maxi,int &ind)
    {
        if(ind>=pre.size()) return NULL;
        
        if(pre[ind]>maxi || pre[ind]<mini) return NULL;
        TreeNode* root=new TreeNode(pre[ind++]);
        root->left=solve(pre,mini,root->val,ind);
        root->right=solve(pre,root->val,maxi,ind);
        return root;       
    }
    TreeNode* solve(vector<int>&pre,int maxi,int &ind)
    {
        if(ind>=pre.size() || pre[ind]>maxi) return NULL;
        
        TreeNode* root=new TreeNode(pre[ind++]);
        root->left=solve(pre,root->val,ind); // If we are going to left upper bound will be root->val
        root->right=solve(pre,maxi,ind);
        return root;       
    }
public:
    TreeNode* bstFromPreorder(vector<int>& pre) {
        int ind=0;
        //return solve(pre,INT_MIN,INT_MAX,ind);
        
        //TC : O(3N)
        //SC : O(N)
        //We can do it by passing only one upper bound
        return solve(pre,INT_MAX,ind);
    }
};