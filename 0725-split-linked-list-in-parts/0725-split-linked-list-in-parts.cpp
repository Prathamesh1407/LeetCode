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
    int getLength(ListNode* head)
    {
        int c=0;
        while(head!=NULL)
        {
            c++;
            head=head->next;
        }
        return c;
    }
public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        vector<ListNode*>ans(k,NULL);
        int l=getLength(head);
        int inEvery=l/k;
        int remainder=l%k;
        //cout<<inEvery+(remainder>0);
        ListNode* curr=head,*prev=NULL,*start=head;
        for(int i=0;i<k;i++)
        {
            ans[i]=curr;
            int p=inEvery+(remainder>0?1:0);
            cout<<p;
            for(int j=0;j<p;j++)
            {
                prev=curr;
                curr=curr->next;
            }
            if(prev) prev->next=NULL;
            remainder--;
        }

        return ans;
        
    }
};