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
    ListNode* mergeTwoLists(ListNode* h1, ListNode* h2) {
    ListNode* dummy= new ListNode(-1);
    ListNode* temp=dummy;

    while(h1 != NULL && h2 != NULL){
        cout<<h1->val<<" "<<h2->val<<endl;
        if(h1->val < h2->val){
            temp->next=h1;
            h1=h1->next;
        }else if(h1->val > h2->val){
            temp->next=h2;
            h2=h2->next;
        }else{
            temp->next=h1;
            
            
            temp=temp->next;
            h1=h1->next;
            temp->next=h2;
            
            h2=h2->next;
        }
        temp=temp->next;
        // temp->next=NULL;
        
    }

    while(h1!=NULL){
        temp->next=h1;
        h1=h1->next;
        temp=temp->next;
    }


    while(h2!=NULL){
        temp->next=h2;
        h2=h2->next;
        temp=temp->next;
    }

    return dummy->next;
    }
};