/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        if(original==NULL) return NULL;
        if(original==target) return cloned;
        TreeNode* res=getTargetCopy(original->left,cloned->left,target);
        if(res) return res;
        return getTargetCopy(original->right,cloned->right,target);
        
    }
};