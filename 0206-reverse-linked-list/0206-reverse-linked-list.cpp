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
    ListNode* reverseList(ListNode* head) {
        if(head==NULL){
            return NULL;
        }
        ListNode* prev=NULL;
        ListNode* next=head->next;
        
        while(head!=NULL){
            head->next=prev;
            prev=head;
            
            head=next;
            if(next!=NULL)
               
                next=next->next;
        }
        
        return prev;
    }
};