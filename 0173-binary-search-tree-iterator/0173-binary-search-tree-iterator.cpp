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
class BSTIterator {
public:
    
    stack<TreeNode*>st;
    BSTIterator(TreeNode* root) {
        pushAllLeft(root);
    }


    
    int next() {
        TreeNode* topnode=st.top();
        st.pop();
        pushAllLeft(topnode->right);// bhai saare right node ke extreme left ko daalegi naa
        return topnode->val;
    }
    
    bool hasNext() {
        
        return !st.empty();
    }
    
private: 
    void pushAllLeft(TreeNode* node){
        while(node!=NULL){
            st.push(node);
            node=node->left;
        }
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */