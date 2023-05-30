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
       int cnt=0;
       ListNode* temp=head;
       while(temp!=NULL){
            cnt++;
            temp=temp->next;
       
       }
       
        int node=cnt-n;
        if(node==0){
            head=head->next;
            return head;
        }
        temp=head;
        
        int pntr=0;
        
        while(pntr<node-1){
            temp=temp->next;
            pntr++;
        }
        
        cout<<temp->val<<endl;
        
        if(temp->next!=NULL)
            temp->next=temp->next->next;
        
        
        return head;
        
        
        
        
        
        
    }
};