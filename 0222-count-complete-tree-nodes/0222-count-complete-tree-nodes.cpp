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
//TC : O(log N*log N) 
//As solve function can only run for log n times because if we go upto the end the other side will have perfect subtree and then we have to run for maximum log N and for finding height log N every time so (log N)^2
//SC : O(log N)
//As we have CBT the overall height will be log N 
class Solution {
    int solve(TreeNode* root)
    {
        if(root==NULL) return 0;
        //calculate the heights of left and right subtree
        int lh=findLeftHeight(root); 
        int rh=findRightHeight(root);
        
        if(lh==rh) return (1<<lh)-1; //2^lh - 1
        //If not give recursive call to the left and right
        
        return 1+solve(root->left)+solve(root->right);
    }
    int findLeftHeight(TreeNode* root)
    {
        //as the Tree is CBT so only count the left side the right side will be proportionally filled and same goes for right side
        int c=0;
        while(root!=NULL)
        {
            root=root->left;
            c++;
        }
        return c;
    }
    int findRightHeight(TreeNode* root)
    {
        int c=0;
        while(root!=NULL)
        {
            root=root->right;
            c++;
        }
        return c;
    }
public:
    int countNodes(TreeNode* root) {
        //We can try any traversal technique pre,in or post but it will end up taking O(N) 
        //so take the advantage of CBT all levels are filled expect last level and if not filled all the all nodes should be on the left side, so if height of left and right subtree is the same so we can apply the formula 2^h-1 and if not apply recursion on left and right side
        
        return solve(root);
        
        
    }
};