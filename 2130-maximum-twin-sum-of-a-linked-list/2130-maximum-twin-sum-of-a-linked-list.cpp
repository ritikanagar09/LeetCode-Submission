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
        
        if(head==NULL || head->next==NULL){
            return head;
        }
        
        ListNode* node=reverse(head->next);
        head->next->next=head;
        head->next=NULL;
        return node;
    }
    int pairSum(ListNode* head) {
        
        
        ListNode* slow=head;
        ListNode* fast=head;
        
        while(fast){
            slow=slow->next;
            fast=fast->next;
            if(fast)
                fast=fast->next;
        }
        
        cout<<slow->val<<endl;
        
        ListNode* h=reverse(slow);
        
        int ans=0;
        ListNode* temp=head;
        while(h!=NULL){
            int k=temp->val+h->val;
            ans=max(ans,k);
            temp=temp->next;
            h=h->next;
            
        }
        
        return ans;
    }
};