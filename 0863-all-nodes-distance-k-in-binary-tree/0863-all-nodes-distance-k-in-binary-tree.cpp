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
    void makeParent(TreeNode* root,unordered_map<TreeNode*,TreeNode*>&parent)
    {
        queue<TreeNode*>q;
        q.push(root);
        parent[root]=NULL;
        while(!q.empty())
        {
            TreeNode* frontNode=q.front();
            q.pop();
            
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
    }
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        //We will do Level order traversal but we have to also keep a track of parent for LOT
        vector<int>ans;
        unordered_map<TreeNode*,TreeNode*>parent; //To Track a parent
        makeParent(root,parent);
        
        unordered_map<TreeNode*,bool>visited; // To track visited nodes
        
        queue<TreeNode*>q;
        q.push(target);
        visited[target]=1;
        int currDistance=0;
        while(!q.empty())
        {
            //If currDistance==k means in the queue all the elements belongs to the distance K from target nodes
            if(currDistance==k) break;            
            currDistance++;
            
            int size=q.size();
            
            for(int i=0;i<size;i++)
            {
                TreeNode* frontNode=q.front();
                q.pop();
                //Both left and right nodes means downwards
                if(frontNode->left && visited[frontNode->left]==false)
                {
                    visited[frontNode->left]=true;
                    q.push(frontNode->left);
                }
                if(frontNode->right && visited[frontNode->right]==false)
                {
                    visited[frontNode->right]=true;
                    q.push(frontNode->right);
                }
                
                //Upwards => Parent
                if(parent[frontNode] && visited[parent[frontNode]]==false)
                {
                    visited[parent[frontNode]]=true;
                    q.push(parent[frontNode]);
                }
            }
            
        }
        while(!q.empty())
        {
            ans.push_back(q.front()->val);
            q.pop();
        }
        return ans;
        
    }
};
