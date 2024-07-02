/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
//TC : O(N1 + N2)
//SC : O(1)
class Solution {
public:
    
    //If lets say N1 is lesser than N2 so move both the pointers simultaneously when the N1 will reach NULL exactly the N2 list will be on N2-N1 node then N1 will go to headB and it will cross that N2-N1 distance and then N2 will reach NULL and then to headA , now both pointers will align and we can find the 1st common node
    
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