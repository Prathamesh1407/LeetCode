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
    void solve(TreeNode* root,int add,int &sum)
    {
        if(root==NULL) return;

        if(root->left==NULL && root->right==NULL && add==1) sum+=root->val;

        solve(root->left,1,sum);
        solve(root->right,0,sum);

    }
public:
    int sumOfLeftLeaves(TreeNode* root) {
        if(root==NULL || (root->left==NULL && root->right==NULL)) return 0;
        int sum=0;
        solve(root,0,sum);
        return sum;
    }
};