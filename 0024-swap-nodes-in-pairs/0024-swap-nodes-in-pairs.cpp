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
        ListNode*temp=fast->next;
        fast->next=slow;
        slow->next=temp;
        prev=slow;
        slow=temp;
        if(slow)
            fast=temp->next;
            else fast=NULL;
        
        
        while(fast){
           cout<<"///"<<endl;
            ListNode*temp=fast->next;
            prev->next=fast;
            cout<<prev->val<<endl;
            cout<<fast->val<<endl;
            fast->next=slow;
            cout<<slow->val<<endl;
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