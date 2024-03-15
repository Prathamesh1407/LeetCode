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
        ListNode* curr=head,*prev=NULL,*nxt=NULL;
        while(curr!=NULL)
        {
            nxt=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nxt;
        }
        return prev;
    }
public:
    int pairSum(ListNode* head) {
        if(head->next==NULL) return head->val; 
        ListNode*h1=head;
        ListNode* middle=getMiddle(head);
        ListNode* h2=reverse(middle->next);
        middle->next=NULL;
        int maxi=INT_MIN;
        while(h2!=NULL)
        {
            maxi=max(maxi,h1->val+h2->val);
            h2=h2->next;
            h1=h1->next;
        }
        return maxi;
        
    }
};