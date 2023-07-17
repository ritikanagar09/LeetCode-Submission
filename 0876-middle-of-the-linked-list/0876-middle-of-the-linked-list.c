/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* middleNode(struct ListNode* head){
    
    if(head==NULL || head->next==NULL){
        return head;
    }
    struct ListNode* slow=head;
    struct ListNode* fast=head;
    
    while(fast->next!=NULL ){
        slow=slow->next;
        fast=fast->next;
        if(fast->next!=NULL){
            fast=fast->next;
        }
    }
    
    return slow;
}