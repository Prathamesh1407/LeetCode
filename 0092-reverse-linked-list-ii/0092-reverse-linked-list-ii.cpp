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
    ListNode* reverseBetween(ListNode* head, int l, int r) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        if(head==NULL || l==r || head->next==NULL) return head;
        ListNode* curr=head,*p=head;
        int i=1;
        while(curr!=NULL)
        {
            
            if(i==l)
            {
                break;
            }
            p=curr;
            curr=curr->next;
            i++;
        }
        ListNode* start=curr,*k=start,*prev=NULL,*nxt=NULL;
        while(start!=NULL && i!=r+1)
        {
            nxt=start->next;
            start->next=prev;
            prev=start;
            start=nxt;
            i++;
        }
        if(l==1)
        {
            head=prev;
        }
        else p->next=prev;
        k->next=nxt;
        return head;  
    }
};