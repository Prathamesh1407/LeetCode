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
    bool solve(TreeNode* l1,TreeNode* r1)
    {
        if(l1==NULL || r1==NULL) return l1==r1;
        
        return l1->val==r1->val && solve(l1->left,r1->right) && solve(l1->right,r1->left);
    }
public:
    bool isSymmetric(TreeNode* root) {
        return solve(root->left,root->right);
    }
};