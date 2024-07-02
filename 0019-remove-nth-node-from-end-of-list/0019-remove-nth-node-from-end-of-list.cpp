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

//Here the fast pointer is moved over length
//TC : O(len)
//TC : O(1)
class Solution {
    
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        
        //Here we will be using the approach of Tortoise and hare move the fast pointer N times and then move the slow and fast by 1,so the fast already moves N times ahead of head the slow will reach to length-N , so in this approach we won't need the length which was taking the O(len) extra
        
        ListNode *fast=head,*slow=head;
        for(int i=0;i<n;i++) 
        {
            fast=fast->next;
        }
        
        //If fast is NULL that means the N = Length so we have to delete the head
        if(fast==NULL)
        {
            ListNode *newHead=head->next;
            delete(head);
            return newHead;
        }
        
        while(fast->next!=NULL) //If fast at the last node then slow will be on the previous node of length-N
        {
            slow=slow->next;
            fast=fast->next;
        }
        
        ListNode* NodeToBeDeleted=slow->next;
        
        slow->next=slow->next->next;
        delete NodeToBeDeleted;
        return head;
    }
};