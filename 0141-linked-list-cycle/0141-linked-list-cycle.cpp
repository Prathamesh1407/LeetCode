/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        if(head==NULL || head->next==NULL) return 0;
        ListNode* slow=head,*fast=head;
        
        while(slow && fast)
        {
            fast=fast->next;
            if(fast) fast=fast->next;
            slow=slow->next;
            if(slow==fast) return true;
        }
        return 0;
    }
};