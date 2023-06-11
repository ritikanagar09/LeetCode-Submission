/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

// reverse = true =before
// reverse=false=next
class BSTIterator {
    bool reverse=true;
public:
    
    stack<TreeNode*>st;
    BSTIterator(TreeNode* root, bool isReverse) {
        reverse=isReverse;
        pushAll(root);
    }

    int next() {
        TreeNode* topnode=st.top();
        st.pop();
        if(!reverse)
            pushAll(topnode->right);// bhai saare right node ke extreme left ko daalegi naa
        else
            pushAll(topnode->left);
        return topnode->val;
    }
    
    bool hasNext() {
        return !st.empty();
    }
    
private: 
    void pushAll(TreeNode* node){
        while(node!=NULL){
            st.push(node);
            
            if(!reverse)
                node=node->left;
            else
                node=node->right;
        }
    }
};



class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        if(!root)return false;
        
        BSTIterator l(root,false); // smallest value ->next
        BSTIterator r(root, true); // greatest value ->before
        
        int i=l.next();
        int j=r.next();// ye hume value de rha h ..ush paricular next node ki 
        
        while(i<j){
            if(i+j==k){
                return true;
            }else if(i+j<k){
                i=l.next();// i++
            }else{
                j=r.next();// j--
            }
        }
        
        return false;
        
    }
};