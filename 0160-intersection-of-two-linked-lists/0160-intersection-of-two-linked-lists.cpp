/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        
        ListNode * h1=headA;
        ListNode * h2=headB;
        
        map<ListNode *, int>mpp;
        
        while(h1 !=NULL){
            mpp[h1]=1;
            h1=h1->next;
        }
        
        while(h2 != NULL){
            
            if(mpp.find(h2) != mpp.end()){
                return h2;
            }
            mpp[h2]=1;
            h2=h2->next;
        }
        
//         while(h1!=NULL || h2!=NULL){
//             if(h1==h2){
//                 return h1;
//             }
            
//             h1=h1->next;
//             h2=h2->next;
            
//             if(h1->next==NULL){
//                 h1=headB;
//             }
            
//             if(h2->next==NULL){
//                 h2=headA;
//             }
//         }
        
        return NULL;
    }
};