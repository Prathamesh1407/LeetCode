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
    int countNode(TreeNode* root)
    {
        if(root==NULL) return 0;
        return 1+countNode(root->left)+countNode(root->right);
    }
    bool isCBT(TreeNode* root,int ind,int nodeCount)
    {
        if(root==NULL) return true;
        if(ind>=nodeCount) return false;
        return isCBT(root->left,2*ind+1,nodeCount) && isCBT(root->right,2*ind+2,nodeCount);
    }
public:
    bool isCompleteTree(TreeNode* root) {
        int nodeCount=countNode(root);
        return isCBT(root,0,nodeCount);
    }
};