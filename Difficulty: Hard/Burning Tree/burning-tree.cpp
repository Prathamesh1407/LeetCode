//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};


Node *buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current Node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current Node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends
//User function Template for C++

/*
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution {
    Node* makeParent(Node* root, unordered_map<Node*,Node*>&parent,int target)
    {
        queue<Node*>q;
        q.push(root);
        parent[root]=NULL;
        Node* res=NULL;
        while(!q.empty())
        {
            Node* frontNode=q.front();
            q.pop();
            
            if(frontNode->data==target) res=frontNode;
            
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
    int minTime(Node* root, int target) 
    {
        // Your code goes here
        queue<Node*>q;
        unordered_map<Node*,bool>visited;
        unordered_map<Node*,Node*>parent;
        
        Node* targetNode=makeParent(root,parent,target);
        q.push(targetNode);
        visited[targetNode]=1;
        int count=0;
        while(!q.empty())
        {
            int size=q.size();
            for(int i=0;i<size;i++)
            {
                Node* frontNode=q.front();
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
            count++;
        }
        return count-1;
    }
};

//{ Driver Code Starts.

int main() 
{
    int tc;
    scanf("%d ", &tc);
    while (tc--) 
    {    
        string treeString;
        getline(cin, treeString);
        // cout<<treeString<<"\n";
        int target;
        cin>>target;
        // cout<<target<<"\n";

        Node *root = buildTree(treeString);
        Solution obj;
        cout<<obj.minTime(root, target)<<"\n"; 

        cin.ignore();

    }


    return 0;
}

// } Driver Code Ends