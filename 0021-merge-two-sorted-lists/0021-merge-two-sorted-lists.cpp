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
    ListNode* solve(ListNode* list1, ListNode* list2){
        if(list1->next==NULL){
            list1->next=list2;
            return list1;
        }
        ListNode* prev=list1;
        ListNode* curr1=list1->next;
        ListNode* curr2=list2;
        ListNode* temp=curr2->next;
        
        while(curr1!=NULL && curr2!=NULL){
            
            if(curr2->val>=prev->val && curr2->val<=curr1->val){
                temp=curr2->next;
                prev->next=curr2;
                curr2->next=curr1;
                
                prev=curr2;//Made errror 
                curr2=temp;
            }else{
                
                prev=curr1;
                curr1=curr1->next;
                
                if(curr1==NULL){
                    prev->next=curr2;
                    return list1;
                }
            }
                
            
        }
        
        return list1;
        
        
    }
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        
        if(list1==NULL){
            return list2;
        }
        
        if(list2==NULL){
            return list1;
        }
        
        if(list1->val<=list2->val){
            return solve(list1,list2);
        }else{
            return solve(list2,list1);
        }
    }
};