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
    bool solve(TreeNode*root,int sum,int tSum)
    {
        if(root==NULL) return 0;

        sum+=root->val;
        //if leaf
        if(root->left==NULL && root->right==NULL)
        {
            if(sum==tSum) return 1;
            return 0;
        }        
        return solve(root->left,sum,tSum) || solve(root->right,sum,tSum);

    }
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root==NULL)
        {
            return 0;
        }
        return solve(root,0,targetSum);
    }
};