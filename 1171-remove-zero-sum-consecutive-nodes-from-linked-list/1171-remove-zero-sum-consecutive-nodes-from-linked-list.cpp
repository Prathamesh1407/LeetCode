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
    ListNode* removeZeroSumSublists(ListNode* head) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        unordered_map<int,ListNode*>m;
        
        ListNode* dummyNode=new ListNode(-1);
        m[0]=dummyNode;
        dummyNode->next=head;
        int pSum=0;
        while(head!=NULL)
        {
            pSum+=head->val;
            if(m.find(pSum)!=m.end())
            {
                ListNode* start=m[pSum];
                ListNode* temp=start;
                int newpSum=pSum;
                while(temp!=head)
                {
                    
                    temp=temp->next;
                    newpSum+=temp->val;
                    if(temp!=head) m.erase(newpSum);
                }
                start->next=head->next;
            }
            else
            {
                m[pSum]=head;
            }
            head=head->next;
        }
        return dummyNode->next;
    }
};