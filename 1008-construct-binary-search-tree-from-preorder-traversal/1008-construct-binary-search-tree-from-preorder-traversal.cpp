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
class Solution {
public:
    
    TreeNode* solve(vector<int>& preorder, int ubound, int &indx){
        if(indx>=preorder.size() || preorder[indx]>ubound ){
            return NULL;
        }
        
        TreeNode* root= new TreeNode(preorder[indx]);
        indx++;
        TreeNode* leftTree=solve(preorder, root->val, indx);
        TreeNode* rightTree=solve(preorder,ubound,indx);
        
        root->left=leftTree;
        root->right=rightTree;
        
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int indx=0;
        return solve(preorder, INT_MAX,indx);
    }
};