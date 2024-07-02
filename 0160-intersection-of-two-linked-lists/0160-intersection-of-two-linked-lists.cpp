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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* a=headA;
        ListNode* b=headB;
        while(a!=b) //If the 1st node is the intersection the loop will break and return 1st node
        {
            a=a->next;
            b=b->next;
            
            if(a==b) return a;
            
            if(a==NULL) a=headB;
            if(b==NULL) b=headA;
        }
        return a;
    }
};