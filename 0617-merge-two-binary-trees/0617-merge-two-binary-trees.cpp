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
    void merge(TreeNode* root1,TreeNode* root2,TreeNode* &root3)
    {
        if(!root1 && !root2) return;
        else if(root1==NULL)
        {
            root3=new TreeNode(root2->val,root2->left,root2->right);
            return;
        }
        else if(root2==NULL)
        {
            root3=new TreeNode(root1->val,root1->left,root1->right);
            return;
        }
        int value=root1->val+root2->val;
        root3=new TreeNode(value);
        merge(root1->left,root2->left,root3->left);
        merge(root1->right,root2->right,root3->right);
    }
public:
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        TreeNode* root3=NULL;
        merge(root1,root2,root3);
        return root3;
    }
};