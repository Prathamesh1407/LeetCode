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
//Approach 1 abs(root-target) find it in BST for every node TC O(n2)
class Solution {
    void inorder(TreeNode* root,vector<int>&ans)
    {
        if(root==NULL) return;
        inorder(root->left,ans);
        ans.push_back(root->val);
        inorder(root->right,ans);
    }
public:
    bool findTarget(TreeNode* root, int k) {
        vector<int>ans;
        inorder(root,ans);
        int i=0,j=ans.size()-1;
        while(i<j)
        {
            int sum=ans[i]+ans[j];
            if(sum==k) return true;
            if(sum>k) j--;
            else i++;
        }
        return false;
    }
};
