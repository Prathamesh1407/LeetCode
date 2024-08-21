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
        ListNode* slow=head;
        ListNode* fast=head->next;
        
        while(fast && fast->next)
        {
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    }
    ListNode* merge(ListNode* left,ListNode* right)
    {
        if(left==NULL) return right;
        if(right==NULL) return left;
        ListNode* ansHead=new ListNode(-1);
        ListNode* ansTail=ansHead;
        while(left && right)
        {
            if(left->val<=right->val)
            {
                ansTail->next=new ListNode(left->val);
                ansTail=ansTail->next;
                left=left->next;
            }
            else
            {
                ansTail->next=new ListNode(right->val);
                ansTail=ansTail->next;
                right=right->next;
            }
        }
        if(left)
        {
            ansTail->next=left;
        }
        if(right)
        {
            ansTail->next=right;
        }
        
        return ansHead->next;
    }
public:
    ListNode* sortList(ListNode* head) {
        if(head==NULL || head->next==NULL) return head;
        
        ListNode* middle=getMiddle(head);
        
        ListNode* left=head,*right=middle->next;
        middle->next=NULL;
        
        left=sortList(left);
        right=sortList(right);
        
        ListNode* result=merge(left,right);
        
        return result;

    }
};