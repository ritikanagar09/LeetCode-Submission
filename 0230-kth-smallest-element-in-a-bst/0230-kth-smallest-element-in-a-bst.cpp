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
    int ans=-1;
    void solve(TreeNode* root, int &i, int k){
        if(root==NULL){
            return;
        }
        solve(root->left,i,k);
        
        i++;
        if(i==k){
            ans=root->val;
        }
        
        solve(root->right,i,k);
        
    }
    int kthSmallest(TreeNode* root, int k) {
        int i=0;
        solve(root,i,k);
        return ans;
        
    }
};