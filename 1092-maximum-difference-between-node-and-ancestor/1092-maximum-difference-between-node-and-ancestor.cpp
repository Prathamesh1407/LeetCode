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
    pair<int,int> solve(TreeNode* root,int& mSum)
    {
        if(root==NULL) return {INT_MAX,INT_MIN};
        if(root->left==NULL && root->right==NULL) return {root->val,root->val};

        pair<int,int> l1=solve(root->left,mSum);
        pair<int,int> r1=solve(root->right,mSum);

        int mini=min(l1.first,r1.first);
        int maxi=max(l1.second,r1.second);

        mSum=max(mSum,max(abs(mini-root->val),abs(maxi-root->val)));

        return {min(mini,root->val),max(maxi,root->val)};
        }
public:
    int maxAncestorDiff(TreeNode* root) {
        if(root==NULL) return 0;
        int mSum=0;
        pair<int,int>temp=solve(root,mSum);
        cout<<temp.first<<" "<<temp.second;
        return mSum;
    }
};