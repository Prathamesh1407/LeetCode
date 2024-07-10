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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int>ans;
        
        TreeNode* curr=root;
        
        while(curr!=NULL)
        {
            if(curr->left==NULL)
            {
                //means it doesn't have left node, so last element of that left subtree , print it
                ans.push_back(curr->val);
                curr=curr->right;
            }
            else
            {
                //Now curr has left node so find the predecessor of that node and link them
                
                //predecessor is the right most node of left subtree
                TreeNode* pred=curr->left;
                
                while(pred->right!=NULL && pred->right!=curr)
                {
                    pred=pred->right;
                }
                
                if(pred->right==NULL)
                {
                    //means it doesn't have any thread to its successor so link it
                    pred->right=curr;
                    ans.push_back(curr->val); //In preorder NLR so whenever we are marking the thread we are at root (node) so print it
                    curr=curr->left;
                }
                else
                {
                    //means it does have thread, remove that thread and move to the right, coz the left subtree is traversed fully 
                    pred->right=NULL;
                    curr=curr->right;
                }
            }
        }
        return ans;
    }
};