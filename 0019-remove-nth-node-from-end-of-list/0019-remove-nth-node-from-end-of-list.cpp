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
            return NULL;
        }
        
        if(head->next==NULL && n==1){
            return NULL;
        }
        ListNode* fast=head;
        ListNode* slow=head;
        
        int cnt=0;
        
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
        
        
        ListNode* node=slow->next;
        
        if(node!=NULL)
            slow->next=node->next;
        
        return head;
    }
};