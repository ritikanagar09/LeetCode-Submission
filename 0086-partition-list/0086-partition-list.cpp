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
    ListNode* partition(ListNode* head, int x) {
        
        ListNode* prev=NULL;
        ListNode* curr=head;
        
        while(curr != NULL){
            
            if(curr->val >= x){
                break;
            }
            
            prev=curr;
            curr=curr->next;
        }
        
        
        
        if(curr==NULL){
            return head;
        }
        
        ListNode* p=curr;
        ListNode* tmp=p->next;
        ListNode* f=NULL;
        
        while( tmp != NULL){
            
            if(tmp->val < x){
                f=tmp->next;
                p->next=f;
                if(prev==NULL){
                    head=tmp;
                 }else{
                    prev->next=tmp;
                }
                
                tmp->next=curr;
                prev=tmp;
                
                
            }
            
            
            
            if( f != NULL ){
                tmp=f;
                f=NULL;
            }else{
                p=tmp;
                tmp=tmp->next;
            }
            
            
            
            
        }
        
        return head;
        
        
        
         
    }
};