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
        if(head==NULL ||head->next==NULL){
            return head;
        }
        
        ListNode* prev=NULL;
        ListNode* curr=head;
        ListNode* next1=head->next;
        int cnt=1;
        while(curr!=NULL && cnt<=k){
            next1=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next1;
            cnt++;
        }
        
        // next1 will be pointing at at the next kth group ki starting me
        
        if(next1!=NULL){
            
            // check if k size kaa group exit bhi krta h kya 
            ListNode* temp=next1;
            int i=0;
            
            while(temp!=NULL && i<k){
                temp=temp->next;
                i++;
            }
             // cout<<i<<endl;
            if(i==k){
                // group exits 
                head->next=reverseKGroup(next1,k);
            }else{
                head->next=next1;
            }
        }
        
        return prev;
        
    }
};