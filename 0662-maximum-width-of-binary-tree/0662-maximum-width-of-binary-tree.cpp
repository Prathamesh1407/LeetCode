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
    int widthOfBinaryTree(TreeNode* root) {
        int maxi=0;
        queue<pair<TreeNode*,long long>>q; // Node,Index
        
        q.push({root,0});
        
        while(!q.empty())
        {
            int size=q.size();
            
            int currentIndex=q.front().second;  
            int levelsLastIndex=q.back().second;
            maxi=max(maxi,levelsLastIndex-currentIndex+1);
            for(int i=0;i<size;i++)
            {
                TreeNode* frontNode=q.front().first;
                int index=q.front().second;
                q.pop();

                if(frontNode->left)
                {
                    q.push({frontNode->left,2LL*index+1});
                }
                if(frontNode->right)
                {
                    q.push({frontNode->right,2LL*index+2});
                }
                
                
            }
        }
        return maxi;
    }
};