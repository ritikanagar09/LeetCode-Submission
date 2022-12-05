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
    int len(ListNode*  head){
        ListNode* temp=head;
        int cnt=0;
        while(temp!=NULL){
            cnt++;
            temp=temp->next;
        }
        
        return cnt;
    }
    ListNode* middleNode(ListNode* head) {
        int mid=(len(head)/2)+1;
        cout<<len(head)<<endl;
        int cnt=1;
        cout<<mid<<endl;
        ListNode* temp=head;
        while(cnt<mid){
           
            temp=temp->next;
            cnt++;
        }
        cout<<temp->val<<endl;
        head=temp;
        return head;
    }
};