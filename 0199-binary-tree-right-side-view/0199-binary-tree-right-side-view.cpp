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
//TC : O(N)
//SC : O(H)
class Solution {
    void solve(TreeNode* root,vector<int>&ans,int level)
    {
        if(root==NULL) return;
        if(ans.size()==level) ans.push_back(root->val);
        solve(root->right,ans,level+1); //First preference will be given to the right side and if the Q is left view then 1st call will be of left
        solve(root->left,ans,level+1);
    }
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int>ans;
        solve(root,ans,0);
        return ans;
    }
};