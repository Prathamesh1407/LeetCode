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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int l=getLength(head);
        n=l-n+1;
        ListNode* curr=head,*dummyNode=new ListNode(-1),*prev=dummyNode;
        dummyNode->next=head;
        int i=1;
        while(true)
        {
            if(i==n)
            {
                prev->next=curr->next;
                break;
            }
            i++;
            prev=curr;
            curr=curr->next;
        }
        return dummyNode->next;
    }
};