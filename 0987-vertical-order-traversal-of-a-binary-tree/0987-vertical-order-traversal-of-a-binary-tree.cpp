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
//TC : O(N * log N) log N for multiset
//SC : O(N+N)
class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int,map<int,multiset<int>>> m; //vertical,level => nodes
        queue<pair<TreeNode*,pair<int,int>>>q; //node,vertical,level
        vector<vector<int>>ans;
        q.push({root,{0,0}});
        
        while(!q.empty())
        {
            auto temp=q.front();
            q.pop();
            TreeNode* frontNode=temp.first;
            int vertical=temp.second.first;            
            int level=temp.second.second;            
            m[vertical][level].insert(frontNode->val);
            
            if(frontNode->left) q.push({frontNode->left,{vertical-1,level+1}});
            if(frontNode->right) q.push({frontNode->right,{vertical+1,level+1}});
        }
        
        for(auto val:m)
        {     
            vector<int>temp;
            for(auto val1:val.second)
            {
                for(auto val2:val1.second)
                {
                    temp.push_back(val2);
                }
            }
            ans.push_back(temp);
            
        }
        return ans;
        
    }
};