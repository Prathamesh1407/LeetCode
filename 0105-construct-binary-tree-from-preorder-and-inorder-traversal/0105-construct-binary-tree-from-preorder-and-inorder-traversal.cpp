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
//T.C : O(n*logn)
class Solution {
    int findPos(vector<int>& in,int s,int e,int x)
    {
        for(int i=s;i<=e;i++)
        {
            if(x==in[i]) return i;
        }
        return -1;
    }
    TreeNode* solve(vector<int>& pre, vector<int>& in,int &ind,int s,int e)
    {
        if(s>e || ind>=pre.size()) return NULL;
        
        int element=pre[ind++];
        
        TreeNode* root=new TreeNode(element);
        int pos=findPos(in,s,e,element);
        //if(pos==-1) return NULL;
        cout<<element<<" "<<pos<<" "<<s<<" "<<e<<endl;
        
        root->left=solve(pre,in,ind,s,pos-1);
        root->right=solve(pre,in,ind,pos+1,e);
        
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int pre=0;
        TreeNode* ans=solve(preorder,inorder,pre,0,inorder.size()-1);
        return ans;
    }
};
