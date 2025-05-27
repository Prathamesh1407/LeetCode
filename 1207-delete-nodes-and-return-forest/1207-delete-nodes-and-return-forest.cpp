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
    TreeNode* solve(TreeNode* root,vector<int>&deleteEle,vector<TreeNode*>&ans)
    {
        if(root==NULL) return NULL;

        root->left=solve(root->left,deleteEle,ans);
        root->right=solve(root->right,deleteEle,ans);

        if(deleteEle[root->val]==1)
        {
            if(root->left!=NULL) ans.push_back(root->left);
            if(root->right!=NULL) ans.push_back(root->right);
            return NULL;
        }
        return root;
    }
public:
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        //Here we have to start from the lower level because if we delete some node from upper side first we will not be in the contacted with below's tree
        vector<TreeNode*>ans;

        vector<int>deleteEle(1001,0);

        for(auto val:to_delete) deleteEle[val]=1;

        TreeNode* root2=solve(root,deleteEle,ans);
        if(deleteEle[root->val]!=1) ans.push_back(root2);
        return ans;
    }
};