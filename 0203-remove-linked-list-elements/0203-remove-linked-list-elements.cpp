/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if(head==NULL) return head;
        if(head->next==NULL)
        {
            if(head->val==val) 
            {
                delete head;
                return NULL;
            }
            else return head;
        }
        ListNode* curr=head,*prev=NULL;
        ListNode* dummyNode=new ListNode(-1);
        dummyNode->next=head;
        prev=dummyNode;
        while(curr!=NULL)
        {
            if(curr->val==val)
            {
                prev->next=curr->next;
            }
            else prev=curr;
            curr=curr->next;
        }
        return dummyNode->next;
    }
};