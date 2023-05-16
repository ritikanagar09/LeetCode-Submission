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
    ListNode* swapPairs(ListNode* head) {
        if(head==NULL || head->next==NULL){
            return head;
        }
        ListNode* fast =head->next;
        ListNode* slow=head;
        
        ListNode*prev=fast;
        
        head=prev;
        
        
        while(fast){
         
            ListNode*temp=fast->next;
            prev->next=fast;
            
            fast->next=slow;
           
            slow->next=temp;
            prev=slow;
            slow=temp;
            if(slow)
                fast=temp->next;
            else fast=NULL;
            
            
        }
        
        
        return head;
    }
};