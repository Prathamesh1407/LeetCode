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

//TC : O(max(len(l1),len(l2)))
//SC : O(max(len(l1),len(l2))) for storing the answer otherwise O(1)
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* ll1, ListNode* ll2) {
        // ListNode * l3=new ListNode(0);
        // int carry=0,value;
        // ListNode * head=l3;
        // while(l2 && l1)
        // {
        //     value=l2->val+l1->val+carry;
        //     carry=value/10;
        //     l3->next=new ListNode(value%10);
        //     l3=l3->next;
        //     l2=l2->next;
        //     l1=l1->next;
        // }
        // while(l1)
        // {
        //     value=l1->val+carry;
        //     carry=value/10;
        //     l3->next=new ListNode(value%10);
        //     l3=l3->next;
        //     l1=l1->next;
        // }
        // while(l2)
        // {
        //     value=l2->val+carry;
        //     carry=value/10;
        //     l3->next=new ListNode(value%10);
        //     l3=l3->next;
        //     l2=l2->next;
        // }
        // if(carry) l3->next=new ListNode(carry);
        // return head->next;
        
        ListNode* dummyNode=new ListNode(-1),*curr=dummyNode,*l1=ll1,*l2=ll2;
        int carry=0;
        while(l1!=NULL || l2!=NULL)
        {
            int sum=carry;
            if(l1!=NULL) sum+=l1->val;
            if(l2!=NULL) sum+=l2->val;
            
            curr->next=new ListNode(sum%10);
            curr=curr->next;
            
            carry=sum/10;
            
            if(l1!=NULL) l1=l1->next;
            if(l2!=NULL) l2=l2->next;   
        }
        if(carry) curr->next=new ListNode(carry);
        return dummyNode->next;
        
    }
};