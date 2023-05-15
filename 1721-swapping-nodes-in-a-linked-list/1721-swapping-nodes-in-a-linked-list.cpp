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
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* left=head;
        ListNode* right=head;
        
        int cnt=0;
        while(cnt<k-1){
            cnt++;
            left=left->next;
            
        }
        
        ListNode* newleft=left;
        
        while(left->next){
            left=left->next;
            right=right->next;
            
        }
        
        cout<<right->val<<endl;
        
        swap(newleft->val,right->val);
        
        return head;
    }
};