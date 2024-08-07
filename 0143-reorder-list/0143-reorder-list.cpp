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
    ListNode* findMiddle(ListNode* head)
    {
        ListNode* fast=head,*slow=head;
        
        while(fast && fast->next)
        {
            fast=fast->next->next;
            slow=slow->next;
        }
        return slow;
    }
    ListNode* reverseLL(ListNode* head)
    {
        ListNode* curr=head,*prev=NULL,*forward=head;
        
        while(curr!=NULL)
        {
            forward=curr->next;
            curr->next=prev;
            prev=curr;
            curr=forward;
        }
        return prev;
    }
    public:
    void reorderList(ListNode* head) {
        if(head==NULL || head->next==NULL) return;
        ListNode* middleNode=findMiddle(head);
        
        ListNode* head2=middleNode->next;
        middleNode->next=NULL;
        head2=reverseLL(head2);
        ListNode* curr=head;
        while(curr && head2)
        {
            ListNode* temp=head2->next;
            head2->next=curr->next;
            curr->next=head2;
            
            curr=head2->next;
            head2=temp;
        }
    }
};