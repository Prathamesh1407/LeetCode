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
    void solve(TreeNode*root,int sum,int tSum,vector<int>output,vector<vector<int>>&ans)
    {
        if(root==NULL) return;

        sum+=root->val;
        output.push_back(root->val);
        //if leaf
        if(root->left==NULL && root->right==NULL)
        {
            if(sum==tSum)
            {
                ans.push_back(output);
            }
            return;
        }        
        solve(root->left,sum,tSum,output,ans);
        solve(root->right,sum,tSum,output,ans);
    }
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if(root==NULL) return {};
        vector<vector<int>>ans;
        solve(root,0,targetSum,{},ans);
        return ans;
    }
};