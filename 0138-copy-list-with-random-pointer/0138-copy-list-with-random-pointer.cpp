/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        
        //Place the copy node next to the original node
        // if org LL 7->13->11->10->1->null ==> 7->7c->13->13c->11->11c->10->10c->1->1c->null  c = copy node
        Node* temp=head;
        while(temp!=NULL)
        {
            Node* newNode=new Node(temp->val);
            newNode->next=temp->next;
            temp->next=newNode;
            temp=temp->next->next;
        }
        
        //Now place the random pointers
        temp=head;
        Node* copyNode=NULL;
        while(temp!=NULL)
        {
            copyNode=temp->next;
            if(temp->random!=NULL) copyNode->random=temp->random->next; //because the copied node is next to original node
            else copyNode->random=NULL;
            temp=temp->next->next;
        }
        
        //Now the separate the copied nodes from the original LL
        temp=head;
        Node* dummyNode=new Node(-1),*curr=dummyNode;
        while(temp!=NULL)
        {
            copyNode=temp->next;
            curr->next=copyNode;
            temp->next=temp->next->next;
            
            temp=temp->next;
            curr=curr->next;
        }
        return dummyNode->next;
    }
};