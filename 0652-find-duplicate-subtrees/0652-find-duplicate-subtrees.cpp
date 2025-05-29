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
    string solve(TreeNode* root,unordered_map<string,int>&m,vector<TreeNode*>&ans)
    {
        if(root==NULL)
        {
            return "N";
        }
        string s=to_string(root->val)+","+solve(root->left,m,ans)+","+solve(root->right,m,ans);

        if(m[s]==1) ans.push_back(root);
        m[s]++;

        return s;
    }
public:
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        //Here we will form the string of subtree and insert it in map

        unordered_map<string,int>m;
        vector<TreeNode*>ans;
        solve(root,m,ans);
        return ans;
    }
};