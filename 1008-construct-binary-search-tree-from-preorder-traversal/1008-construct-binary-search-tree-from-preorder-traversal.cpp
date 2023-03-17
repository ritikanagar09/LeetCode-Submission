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
    // we are storing only upper bound
    // by reference-> agar nhi lagayenge toh i ki value stack ke acoording change hoti rahegi ..that we dont want we want it to traverse over arrays in increaing order. 
    TreeNode* solve(int bound, vector<int>&preorder, int &i){
        
        if(i>=preorder.size() || preorder[i]>=bound){
            return NULL;
        }
        
        
        TreeNode* root=new TreeNode(preorder[i]);
        i++;
        TreeNode* l=solve( root->val, preorder,i);
        TreeNode* r=solve(bound, preorder,i);
     
        root->left=l;
        root->right=r;
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        // int i;
        int i=0;
        return solve(INT_MAX,preorder,i);
        
    }
};