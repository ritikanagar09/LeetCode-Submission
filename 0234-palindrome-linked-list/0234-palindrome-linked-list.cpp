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
    ListNode* reverse(ListNode* head){
        if(head==NULL ||head->next==NULL){
            return head;
        }
        ListNode*prev=NULL;
        ListNode* curr=head;
        ListNode* next=NULL;
        while(curr!=NULL){
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        
        return prev;
    }
    bool isPalindrome(ListNode* head) {
        
        
        ListNode* slow=head;
        ListNode* fast=head;
        
//         while(fast->next!=NULL){
            
//             fast=fast->next;
//             if(fast->next){
//                 fast=fast->next;
//             }
            
//             slow=slow->next;
//         }
        
        
        while(fast->next!=NULL && fast->next->next != NULL){
            
            fast=fast->next->next;
            
            slow=slow->next;
        }
        
        slow->next=reverse(slow->next);
        slow=slow->next;
        
        while(slow!=NULL){
            if(head->val!=slow->val){
                return false;
            }
            
            head=head->next;
            slow=slow->next;
        }
        
        return true;
        
    }
};