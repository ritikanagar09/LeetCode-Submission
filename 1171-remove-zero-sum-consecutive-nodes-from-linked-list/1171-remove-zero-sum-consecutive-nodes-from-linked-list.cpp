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
    ListNode* removeZeroSumSublists(ListNode* head) {
        ListNode* dummy= new ListNode(0,head);// it is pointing head's next 
        
        ListNode* curr=dummy;
        int psum=0;
        unordered_map<int,ListNode*>mpp;
        
        while(curr != NULL){
            psum+=curr->val;
            if(mpp.find(psum) != mpp.end()){
                ListNode* start=mpp[psum];
                
                // dont forget to delete the nodes from map
                curr=start->next;
                
                int sum=psum+curr->val;
                while(sum != psum){ // 6 --> 3 
                    mpp.erase(sum);
                    curr=curr->next;
                    sum+=curr->val;
                }
                
                
                 start->next=curr->next;
                
            }else{
                mpp[psum]=curr;
            }
            
            curr=curr->next;
        }
        return dummy->next;
        
    }
};