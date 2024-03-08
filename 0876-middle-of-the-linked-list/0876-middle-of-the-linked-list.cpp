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
    ListNode* middleNode(ListNode* head) {
        
        if(head==NULL){
            return head;
        }
        int n=0;
        
        ListNode* temp=head;
        
        while(temp != NULL){
            temp=temp->next;
            n++;
        }
        
        int cnt=0;
        
        temp=head;
        n=n/2;
        cout<<n<<endl;
        while(temp!=NULL && cnt < n){
            temp=temp->next;
            cnt++;
        }
        
        return temp;
    }
};