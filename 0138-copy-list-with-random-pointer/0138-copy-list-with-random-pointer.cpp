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
        Node* copyHead=NULL,*copyTail;
        Node*orgNode=head;
        while(orgNode)
        {
            if(copyHead==NULL)
            {
                copyHead=new Node(orgNode->val);
                copyTail=copyHead;
            }
            else
            {
                copyTail->next=new Node(orgNode->val);
                copyTail=copyTail->next;    
            }
            orgNode=orgNode->next;
        }
        orgNode=head;
        Node* cloneNode=copyHead,*nxt=NULL;
        //Changing the links of the pointer
        while(orgNode!=NULL)
        {
            nxt=orgNode->next;
            orgNode->next=cloneNode;
            orgNode=nxt;
            
            nxt=cloneNode->next;
            cloneNode->next=orgNode;
            cloneNode=nxt;
        }
        
        //Place the random pointers
        orgNode=head;
        while(orgNode)
        {
            orgNode->next->random=orgNode->random?orgNode->random->next:NULL;
            orgNode=orgNode->next->next;
        }
        
        //Unlink the LL
        orgNode=head;
        cloneNode=copyHead;
        while(orgNode)
        {
            orgNode->next=cloneNode->next;
            orgNode=orgNode->next;
            
            if(orgNode!=NULL) cloneNode->next=orgNode->next;
            cloneNode=cloneNode->next;
        }
        return copyHead;
    }
};