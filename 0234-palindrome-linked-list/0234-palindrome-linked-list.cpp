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
    ListNode* getMiddle(ListNode* head)
    {
        if(head->next==NULL) return head;
        if(head->next->next==NULL) return head;
        ListNode* slow=head,*fast=head->next;
        while(fast && fast->next)
        {
            fast=fast->next->next;
            slow=slow->next;
        }
        return slow;
    }
    ListNode* reverse(ListNode* head)
    {
        ListNode* start=head,*prev=NULL,*nxt=NULL;
        while(start!=NULL)
        {
            nxt=start->next;
            start->next=prev;
            prev=start;
            start=nxt;
        }
        return prev;
    }
public:
    bool isPalindrome(ListNode* head) {
        if(head->next==NULL) return true;
        
        ListNode* middle=getMiddle(head);
        ListNode* h1=head;
        ListNode* h2=reverse(middle->next);
        middle->next=NULL;
        while(h2)
        {
            if(h2->val!=h1->val) return 0;
            h1=h1->next;
            h2=h2->next;
        }
        return 1;
    }
};