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
//TC : O(2N) Every Node will be traversed approx 2 times, once for establishing the temporary link and once for reverting it
//SC : O(1)
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
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
                    curr=curr->left;
                }
                else
                {
                    //means it does have thread, remove that thread and move to the right, coz the left subtree is traversed fully 
                    pred->right=NULL;
                    ans.push_back(curr->val);
                    curr=curr->right;
                }
            }
        }
        return ans;
    }
};