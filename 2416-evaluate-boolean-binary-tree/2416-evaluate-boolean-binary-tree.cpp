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
    bool solve(TreeNode* root)
    {
        if(root->left==NULL && root->right==NULL) return root->val;

        int left=solve(root->left);
        int right=solve(root->right);

        if(root->val==2) return left|right;
        return left&right;
    }
public:
    bool evaluateTree(TreeNode* root) {
        if(root==NULL) return 0;
        return solve(root);
    }
};