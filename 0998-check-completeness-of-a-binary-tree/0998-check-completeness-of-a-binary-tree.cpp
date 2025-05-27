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
    bool isCompleteTree(TreeNode* root) {
        //A1:BFS, we will see if previously for that level have we encountered with null
        int isNull=0;
        queue<TreeNode*>q;

        q.push(root);
        while(!q.empty())
        {
            int size=q.size();
            while(size--)
            {
                auto node=q.front();
                q.pop();
                if(node->left==NULL && node->right==NULL) 
                {
                    isNull=1; //if another subtree is there 
                    continue;
                }
                if(isNull==1) return 0;

                if(node->left!=NULL) q.push(node->left);
                else isNull=1;

                
                if(node->right!=NULL && isNull!=1) q.push(node->right);
                else if(isNull) return 0;
                else isNull=1;
            }
            //isNull=0;
        }
        return 1;
    }
};