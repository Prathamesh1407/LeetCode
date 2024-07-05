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
//TC :O(N)
//SC :O(N)
class Solution {
    int solve(TreeNode* root,int &diameter)
    {
        if(root==NULL) return 0;
        
        int lh=solve(root->left,diameter);
        int rh=solve(root->right,diameter);
        
        diameter=max(diameter,lh+rh);
        return 1+max(lh,rh);
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int diameter=0;
        int height=solve(root,diameter);
        return diameter;
    }
};