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
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
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


//2nd Approach  1-Pass Sol
//find k th element store the Node keep temp on kth->next , put p2 on head traverse both until end p2 will be on n-k th node and swap the nodes
