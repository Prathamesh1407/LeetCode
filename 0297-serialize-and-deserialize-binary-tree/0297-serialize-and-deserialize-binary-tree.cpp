/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root==NULL) return "";
        queue<TreeNode*>q;
        q.push(root);
        string ans="";
        
        while(!q.empty())
        {
            TreeNode* frontNode=q.front();
            q.pop();
            
            //Here comma is inserted as delimiter while decoding the data and # is for NULL
            if(frontNode==NULL) ans.append("#,");
            else ans.append(to_string(frontNode->val)+",");
            
            if(frontNode!=NULL) //If current Node is NULL then there's no left and right
            {
                q.push(frontNode->left);
                q.push(frontNode->right);
            }
        }
        //cout<<ans;
        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        //For the deserializing we will use the stringstream it will allows us to take the input from string like a stream
        if(data.length()==0) return NULL;
        stringstream s (data);
        string temp;
        
        //The getline() function extracts characters from the input stream and appends it to the string object until the delimiting character is encountered.
        
        getline(s,temp,','); //, as a delimiter  => istream& getline(istream& is,string& str, char delim);
        
        queue<TreeNode*>q;
        TreeNode* root=new TreeNode(stoi(temp));
        q.push(root);
        
        while(!q.empty())
        {
            TreeNode* frontNode=q.front();
            q.pop();
            
            //left Node of frontNode 
            getline(s,temp,',');
            if(temp=="#")
            {
                frontNode->left=NULL;
            }
            else
            {
                frontNode->left=new TreeNode(stoi(temp));
                q.push(frontNode->left);
            }
            
            //right Node of frontNode 
            getline(s,temp,',');
            if(temp=="#")
            {
                frontNode->right=NULL;
            }
            else
            {
                frontNode->right=new TreeNode(stoi(temp));
                q.push(frontNode->right);
            }
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));