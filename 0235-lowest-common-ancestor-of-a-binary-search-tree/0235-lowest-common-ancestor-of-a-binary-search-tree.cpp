/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        while(root!=NULL)
        {
            if(root->val<p->val && root->val<q->val)
            {
                //If both lies on right go to the right
                root=root->right;
            }
            else if(root->val>p->val && root->val>q->val)
            {
                //If both lies on left go to the left
                root=root->left;
            }
            else return root; // if both gets apart or split that will be your LCA
        }
        return root;
    }
};