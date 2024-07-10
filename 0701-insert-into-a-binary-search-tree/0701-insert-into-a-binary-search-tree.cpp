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
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root==NULL)
        {
            return new TreeNode(val);
        }
        TreeNode* prev=NULL,*root1=root;
        while(root1!=NULL)
        {
            prev=root1;
            if(val>root1->val)
            {
                root1=root1->right;
            }
            else root1=root1->left;   
        }
        
        if(prev->val>val) prev->left=new TreeNode(val);
        else prev->right=new TreeNode(val);
        return root;
    }
};