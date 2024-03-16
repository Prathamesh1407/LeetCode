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
    int getLength(ListNode* head)
    {
        int c=0;
        while(head!=NULL)
        {
            c++;
            head=head->next;
        }
        return c;
    }
public:
    ListNode* rotateRight(ListNode* head, int k) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        if(head==NULL || k==0 || head->next==NULL) return head;
        int l=getLength(head);
        k=k%l;
        if(k==0) return head;
        ListNode*curr=head,*p,*m;
        k=l-k;
        int i=1;
        while(curr->next)
        {
            if(i==k)
            {
                p=curr;
            }
            i++;
            curr=curr->next;
        }
        m=p->next;
        p->next=NULL;
        curr->next=head;
        return m;
    }
};