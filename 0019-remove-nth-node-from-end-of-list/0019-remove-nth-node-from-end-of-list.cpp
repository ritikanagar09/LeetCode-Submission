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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head==NULL){
            return head;
        }
        ListNode* dummy=head;
        ListNode* fast=dummy;
        ListNode* slow=dummy;
        
        while(n--){
            fast=fast->next;
        }
        
        if(fast==NULL){
            head=head->next;
            return head;
        }
        while(fast->next!=NULL){
            slow=slow->next;
            fast=fast->next;
        }
        
        if(slow->next!=NULL)
            slow->next=slow->next->next;
        
        return head;
        
    }
};