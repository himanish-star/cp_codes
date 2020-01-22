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
    ListNode* reverseList(ListNode* head) {
        if(!head)
            return head;
        
        if(!head->next)
            return head;
        
        ListNode* tail=head;
        while(tail->next && tail->next->next) {
            tail=tail->next;
        }
        
        ListNode* temp=tail->next;
        tail->next=NULL;
        
        temp->next=reverseList(head);
        return temp;
    }
};