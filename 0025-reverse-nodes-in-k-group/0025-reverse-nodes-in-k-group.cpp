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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(!head || !head->next){
            return head;
        }
        
        int x=k;
        
        ListNode* tmp=head;
        
        while(x>0 && tmp!=NULL){
            tmp=tmp->next;
            x--;
        }
        
        if(x==0){
            
            ListNode* prev=NULL;
            ListNode* curr=head;
            ListNode* next=curr->next;
            
            int n=k;
            while(n > 0 && curr != NULL){
                next=curr->next;
                curr->next=prev;
                prev=curr;
                curr=next;
                n--;
            }
            
            head->next=reverseKGroup(curr,k);
            return prev;
        }else{
            return head;
        }
         
        
    }
};