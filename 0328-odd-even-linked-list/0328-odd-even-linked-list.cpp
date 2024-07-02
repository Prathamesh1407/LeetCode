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
    ListNode* oddEvenList(ListNode* head) {
        if(head==NULL || head->next==NULL) return head;
        
        ListNode *odd=head,*even=head->next,*evenHead=head->next;
        
        //coz Even will be ahead of odd so if we apply the condition on even it will be also get applied for odd
        while(even!=NULL && even->next!=NULL)
        {
            odd->next=odd->next->next;
            even->next=even->next->next;
            
            //Now we have to move pointers to the next appropriate index but now the odd and even is on their respective next odd and even so only to the next not to the next->next
            odd=odd->next;
            even=even->next;
        }
        //Now join the odd to the even
        odd->next=evenHead;
        return head;
    }
};