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
        map<ListNode*,int>mpp;
        
        ListNode* tmp=headA;
        while(tmp!=NULL){
            mpp[tmp]=1;
            tmp=tmp->next;
        }
        
        tmp=headB;
        
        while(tmp != NULL){
            
            if(mpp.find(tmp)!=mpp.end()){
                return tmp;
            }
            
            tmp=tmp->next;
        }
        
        return NULL;
    }
};