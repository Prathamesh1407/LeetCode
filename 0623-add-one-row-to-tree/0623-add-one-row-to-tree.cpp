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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth==1)
        {
            TreeNode* newRoot=new TreeNode(val);
            newRoot->left=root;
            return newRoot;
        }
        queue<TreeNode*>q;
        q.push(root);
        int level=1;

        while(!q.empty())
        {
            int size=q.size();
            if(depth-1==level)
            {
                while(size--)
                {
                    TreeNode* node=q.front();
                    q.pop();
                    // cout<<node->val<<" ";
                    TreeNode* oldLeft=node->left;
                    TreeNode* oldRight=node->right;

                    node->left=new TreeNode(val);
                    node->right=new TreeNode(val);

                    node->left->left=oldLeft;
                    node->right->right=oldRight;
                }
                return root;
            }
            else
            {
                while(size--)
                {
                    TreeNode* node=q.front();
                    q.pop();
                    
                    if(node->left!=NULL) 
                    {
                        q.push(node->left);
                    }
                    if(node->right!=NULL) q.push(node->right);
                }
            }
            level++;

        }
        return root;
    }
};