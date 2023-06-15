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
    void solve(TreeNode* root, int &mini, int &prev){
        if(root==NULL){
            return;
        }
        
        solve(root->left,mini,prev);
        if(prev!=-1){
            mini=min(mini,abs(prev-root->val));
        }
        
        prev=root->val;
        
        solve(root->right,mini,prev);
    }
    int getMinimumDifference(TreeNode* root) {
        
        int mini=INT_MAX;
        int prev=-1;
        solve(root,mini,prev);
        
        return mini;
    }
};