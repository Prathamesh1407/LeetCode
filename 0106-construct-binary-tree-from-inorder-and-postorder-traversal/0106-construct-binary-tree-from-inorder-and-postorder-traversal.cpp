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
    TreeNode* solve(vector<int>& in, vector<int>& post,int &ind,int s,int e)
    {
        if(s>e || ind<0) return NULL;
        
        int element=post[ind--];
        TreeNode* root=new TreeNode(element);
        int pos=findPos(in,s,e,element);
        
        root->right=solve(in,post,ind,pos+1,e);
        root->left=solve(in,post,ind,s,pos-1);
        
        return root;
        
    }
        TreeNode* solve2(vector<int>& postorder, vector<int>& inorder,int &ind,int s,int   e,unordered_map<int,int>&m)
    {
        if(s>e || ind<0) return NULL;
        
        int element=postorder[ind];
        ind--;
        TreeNode* root=new TreeNode(element);
        int indInInorder=m[element];
        
        root->right=solve2(postorder,inorder,ind,indInInorder+1,e,m);
        root->left=solve2(postorder,inorder,ind,s,indInInorder-1,m);
        
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& in, vector<int>& post) {
        
        //TC : O(N* log N)
        //SC : O(N)
        //A1: Solve this by finding the index of postorder element in the inorder
        /*
        int postInd=in.size()-1;
        TreeNode* ans=solve(in,post,postInd,0,postInd);
        return ans;
        */
        
        //TC : O(N)
        //SC : O(N)
        //A2: Instead of finding the index of postorder element in the inorder store it in the map and access it in constant time
        
        int postInd=post.size()-1;
        unordered_map<int,int>m;
        for(int i=0;i<in.size();i++)
        {
            m[in[i]]=i;
        }
        TreeNode* ans=solve2(post,in,postInd,0,post.size()-1,m);
        return ans;
    }
};