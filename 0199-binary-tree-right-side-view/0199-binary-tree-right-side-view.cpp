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
    vector<int> rightSideView(TreeNode* root) {
        //A1:BFS
        if(root==NULL) return {};
    
        vector<int>ans;
        queue<TreeNode*>q;
        q.push(root);

        while(!q.empty())
        {
            //take a size of queue that much element will be in the one level and last elemet will be our answer
            int qSize=q.size();
            TreeNode* node=NULL;
            while(qSize--)
            {
                node=q.front();
                q.pop();
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            //Now here the last element in row will be in the variable node
            ans.push_back(node->val);
        }
        return ans;
    }
};