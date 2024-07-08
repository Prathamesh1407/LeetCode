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
    TreeNode* solve2(vector<int>& preorder, vector<int>& inorder,int &ind,int s,int e,unordered_map<int,int>&m)
    {
        if(s>e || ind>=preorder.size()) return NULL;
        
        int element=preorder[ind];
        ind++;
        TreeNode* root=new TreeNode(element);
        int indInInorder=m[element];
        
        root->left=solve2(preorder,inorder,ind,s,indInInorder-1,m);
        root->right=solve2(preorder,inorder,ind,indInInorder+1,e,m);
        
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        
        //TC : O(N*logN) coz we are searching in the range of s and e so it's getting divide by 2 every time so log N
        //SC : O(N)
        //A1: Solve this by finding the index of preorder element in the inorder
        
        // int pre=0;
        // TreeNode* ans=solve(preorder,inorder,pre,0,inorder.size()-1);
        // return ans;
        
        
        //TC : O(N)
        //SC : O(N)
        //A2: Instead of finding the index of preorder element in the inorder store it in the map and access it in constant time
        int pre=0;
        unordered_map<int,int>m;
        for(int i=0;i<inorder.size();i++)
        {
            m[inorder[i]]=i;
        }
        TreeNode* ans=solve2(preorder,inorder,pre,0,inorder.size()-1,m);
        return ans;
    }
};
