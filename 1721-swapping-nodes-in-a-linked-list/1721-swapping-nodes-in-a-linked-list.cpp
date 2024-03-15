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
    ListNode* swapNodes(ListNode* head, int k) {
        if(head==NULL || head->next==NULL) return head; 
        ListNode*curr=head;
        int l=getLength(head),last=l-k+1;
        ListNode *f,*s;
        int i=1,j=1;
        bool flag1,flag2;
        while(curr)
        {
            if(k==i)
            {
                f=curr;
            }
            if(last==i)
            {
                s=curr;
            }
            curr=curr->next;
            i++;
        }
        cout<<s->val<<" "<<f->val;
        swap(s->val,f->val);
        return head;
    }
};