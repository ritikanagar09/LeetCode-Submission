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
        if(h1->val < h2->val){
            temp->next=h1;
            h1=h1->next;
        }else{
            temp->next=h2;
            h2=h2->next;
        }
        temp=temp->next; 
    }

    if(h1!=NULL){
        temp->next=h1;
    }


    if(h2!=NULL){
        temp->next=h2;
     }

    return dummy->next;
    }
};