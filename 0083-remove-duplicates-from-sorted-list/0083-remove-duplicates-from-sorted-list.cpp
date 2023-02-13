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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==NULL){
            return NULL;
        }
       ListNode* h1=head;
       ListNode* h2=head->next;
       while(h2!=NULL){
           if(h1->val==h2->val){
               h1->next=h2->next;
               h2=h2->next;
           }else{
               h1=h2;
               h2=h2->next;
           }
       }
        
        return head;
    }
};