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
//TC : O(2N)
//SC : O(1)
class Solution {
    
public:
    ListNode* rotateRight(ListNode* head, int k) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        
        if(head==NULL || k==0 || head->next==NULL) return head;
        
        
        int len=1;
        ListNode*tail=head;
        while(tail->next!=NULL)
        {
            len++;
            tail=tail->next;
        }

        k=k%len;
        if(k==0) return head;
        
        tail->next=head;
        k=len-k;
        
        ListNode*KthNode=tail;
        //Now let's get the Kth Node
        
        while(k--)
        {
            KthNode=KthNode->next;
        }
        cout<<KthNode->val;
        head=KthNode->next;
        KthNode->next=NULL;
        return head;
    }

};