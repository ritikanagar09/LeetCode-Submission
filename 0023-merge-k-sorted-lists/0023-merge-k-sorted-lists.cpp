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

class cmp{
    
    public:// important
    bool operator() (ListNode* a, ListNode* b)
    {
        return a->val>b->val;
    }
};

class Solution {
    
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty()){
            return NULL;
        }
        
        
        priority_queue<ListNode*, vector<ListNode*>,cmp>pq;
        
        for (auto heads: lists){
            if(heads!=NULL)
                pq.push(heads);
        }
        
        ListNode* dummy=new ListNode(-1);
        ListNode* tail=dummy;
        while(!pq.empty()){
            ListNode* front=pq.top();
            pq.pop();
            tail->next=front;
            tail=front;
            if(front->next!=NULL){// this part is imprtant 
                pq.push(front->next);
            }
            
        }
        
        return dummy->next;
        
    }
};