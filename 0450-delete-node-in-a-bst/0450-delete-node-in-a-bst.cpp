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
    TreeNode* findMin(TreeNode* root)
    {
        while(root->left)
        {
            root=root->left;
        }
        return root;
    }
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root==NULL) return NULL;
        if(root->val>key)
        {
            root->left=deleteNode(root->left,key);
            return root;
        }
        else if(root->val<key)
        {
            root->right=deleteNode(root->right,key);
            return root; 
        }
        else
        {
            //Node Found
            
            //If node is a leaf node
            if(root->left==NULL && root->right==NULL) 
            {
                delete root;
                return NULL;
            }
            
            //If any one side is NULL then store the address of opposite subtree and return it
            if(root->left==NULL)
            {
                TreeNode* p=root->right;
                delete root;
                return p;
            }
            if(root->right==NULL)
            {
                TreeNode* p=root->left;
                delete root;
                return p;
            }
            
            //If node has both left and right then choose the minimum of right subtree or maximum of left subtree
            
            TreeNode* p=findMin(root->right);
            root->val=p->val;
            root->right=deleteNode(root->right,p->val);
            return root;
        }
    }
};