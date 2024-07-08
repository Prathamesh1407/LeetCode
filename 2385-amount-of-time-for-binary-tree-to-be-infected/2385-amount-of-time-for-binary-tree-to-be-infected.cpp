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
    TreeNode* makeParent(TreeNode* root, unordered_map<TreeNode*,TreeNode*>&parent,int target)
    {
        queue<TreeNode*>q;
        q.push(root);
        parent[root]=NULL;
        TreeNode* res=NULL;
        while(!q.empty())
        {
            TreeNode* frontNode=q.front();
            q.pop();
            
            if(frontNode->val==target) res=frontNode;
            
            if(frontNode->left)
            {
                q.push(frontNode->left);
                parent[frontNode->left]=frontNode;
            }
            if(frontNode->right)
            {
                q.push(frontNode->right);
                parent[frontNode->right]=frontNode;
            }
        }
        return res;
    }
public:
    int amountOfTime(TreeNode* root, int start) {
        queue<TreeNode*>q;
        unordered_map<TreeNode*,bool>visited;
        unordered_map<TreeNode*,TreeNode*>parent; //We can't traverse back so make a mapping of parents
        
        TreeNode* targetNode=makeParent(root,parent,start); //while mapping also get the address of targetNode
        q.push(targetNode);
        visited[targetNode]=1;
        int count=0;
        while(!q.empty())
        {
            int size=q.size();
            for(int i=0;i<size;i++)
            {
                TreeNode* frontNode=q.front();
                q.pop();
                
                if(frontNode->left && visited[frontNode->left]==false)
                {
                    q.push(frontNode->left);
                    visited[frontNode->left]=1;
                }
                if(frontNode->right  && visited[frontNode->right]==false)
                {
                    q.push(frontNode->right);
                    visited[frontNode->right]=1;
                }
                if(parent[frontNode] && visited[parent[frontNode]]==false)
                {
                    q.push(parent[frontNode]);
                    visited[parent[frontNode]]=1;
                }
            }
            count++; //In each and every levels some elements will get infected so increase the counter
        }
        return count-1; //but at last level the counter will increase but there is no any further levels so decrement the counter by 1
    }
};