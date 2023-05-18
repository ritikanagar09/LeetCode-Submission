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
    void deleteNode(ListNode* node) {
        
        // abhi vali approach we are actually not deleting anything here 
        
        //abhi toh bss ponter hata deer hai hum 
        
        node->val=node->next->val;
        
        node->next=node->next->next;
    }
};