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
        if(head==NULL || head->next==NULL){
            return head;
        }
        
        // pehle hi node ki count measure kr le 
        
        int x=k;
        ListNode* temp=head;
        while(x >0 && temp!=NULL){
            temp=temp->next;
            x--;
        }
        
        
        
        if(x==0){
            ListNode* prev=NULL;
            ListNode* curr= head;
            ListNode*next=curr->next;

            int n=k;

            while(n--){
                next=curr->next;
                curr->next=prev;
                prev=curr;
                curr=next;
            }

            // paagal aurat ..ynhar head bhi oth tha ek p

            head->next=reverseKGroup(curr,k);

            return prev;
        }else{
            return head;
        }
        
        
        
    }
};