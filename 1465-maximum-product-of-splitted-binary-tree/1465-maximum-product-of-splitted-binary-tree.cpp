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
    int getSum(TreeNode* root)
    {
        if(root==NULL) return 0;
        return root->val+getSum(root->left)+getSum(root->right);
    }
    int solve(TreeNode* root,long long sum,long long & maxi)
    {
        if(root==NULL) return 0;

        int l=solve(root->left,sum,maxi);
        int r=solve(root->right,sum,maxi);
        
        long long subTreeSum=l+r+root->val;
        maxi=max(maxi,subTreeSum*(sum-subTreeSum));
        return subTreeSum;
    }
public:
    int maxProduct(TreeNode* root) {
        long long sum=getSum(root);
        long long maxi=0;
        solve(root,sum,maxi);
        return maxi%(1000000007);
    }
};