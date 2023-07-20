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
    int maxi=INT_MIN;
int solve(TreeNode* root){
    
    if(root==NULL){
        return 0;
    }
    
    int leftans=max(0,solve(root->left));
    int rightans=max(0,solve(root->right));
    
    // int cond=leftans+rightans+root->val;
    int ans=leftans+rightans+root->val;
    maxi=max(ans,maxi);
    
    return max(leftans,rightans)+root->val;
    
    
}
    int maxPathSum(TreeNode* root) {
        solve(root);
        
        return maxi;
    }
};