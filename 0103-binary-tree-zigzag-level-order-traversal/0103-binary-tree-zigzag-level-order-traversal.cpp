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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(root==NULL) return {};
        vector<vector<int>> ans;
        queue<TreeNode*>q;
        bool ltr=1;
        q.push(root);
        while(!q.empty())
        {
            int size=q.size();
            vector<int>v(size);
            
            for(int i=0;i<size;i++)
            {
                TreeNode* frontNode=q.front();
                q.pop();
                
                int index=ltr?i:size-i-1;
                
                v[index]=frontNode->val;
                
                if(frontNode->left) q.push(frontNode->left);
                if(frontNode->right) q.push(frontNode->right);
            }
            ltr=!ltr;
            ans.push_back(v);
        }
        return ans;
    }
};