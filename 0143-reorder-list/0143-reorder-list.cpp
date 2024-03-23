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
    void reorderList(ListNode* head) {
        ListNode*h=head;
        vector<ListNode*>v;
        while(h)
        {
            v.push_back(h);
            h=h->next;
        }
        int i=0,j=v.size()-1;
        head=v[i];
        head->next=v[j];
        h=head->next;
        i++; 
        while(j>i)
        {
            h->next=v[i];
            h=h->next;
            j--;
            h->next=v[j];
            h=h->next;
            i++;
        }
        h->next=NULL;
    }
};