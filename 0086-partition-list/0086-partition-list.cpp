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
    ListNode* partition(ListNode* head, int x) {
        ListNode *left=new ListNode(-1);
        ListNode *right=new ListNode(-1);
        ListNode *ltail=left,*rtail=right,*curr=head;
        
        while(curr!=NULL)
        {
            if(curr->val<x)
            {
                ltail->next=curr;
                ltail=ltail->next;
            }
            else
            {
                rtail->next=curr;
                rtail=rtail->next;
            }
            curr=curr->next;
        }
        
        ltail->next=right->next;
        rtail->next=NULL;
        return left->next;
    }
};