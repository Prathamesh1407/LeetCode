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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* curr2=list2;
        while(curr2->next) curr2=curr2->next;
        ListNode* curr1=list1,*nxt=NULL,*prev=NULL;
        int i=1;
        while(curr1)
        {
            if(i==a) prev=curr1;
            if(i==b+1) 
            {
                nxt=curr1->next;
                prev->next=NULL;
                break;
            }
            curr1=curr1->next;
            i++;
        }
        cout<<prev->val<<" "<<nxt->val;
        prev->next=list2;
        curr2->next=nxt;
        return list1;
    }
};