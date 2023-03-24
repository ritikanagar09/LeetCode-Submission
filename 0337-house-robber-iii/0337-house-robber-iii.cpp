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
    
    int solve(TreeNode* root, unordered_map<TreeNode*,int>&mp){
        if(root==NULL){
            return 0;
        }
        
        if(mp.find(root)!=mp.end()){
            return mp[root];
        }
        
        int not_take=0+solve(root->left,mp)+solve(root->right,mp);
        
        int take=root->val;
        if(root->left){
            take+=solve(root->left->left,mp)+solve(root->left->right,mp);
        }
        
        if(root->right){
            take+=solve(root->right->left,mp)+solve(root->right->right,mp);
        }
        
        
        return mp[root]=max(not_take,take);
    }
    int rob(TreeNode* root) {
        if(root==NULL){
            return 0;
        }
        
        unordered_map<TreeNode*,int>mp;
        return solve(root,mp);
    }
};