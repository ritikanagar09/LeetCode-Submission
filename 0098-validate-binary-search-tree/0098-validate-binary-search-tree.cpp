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
    bool solve(TreeNode* root, long long mini, long long maxi){
        
        if(root==NULL){
            return true;
        }
        
        bool cond1= (root->val > mini && root->val < maxi);
        
        bool l=solve(root->left,mini,root->val);
        bool r=solve(root->right,root->val,maxi);
        
        return (cond1&&l&&r);
        
    }
    bool isValidBST(TreeNode* root) {
        
        long long mini=INT_MIN;
        long long maxi=INT_MAX;
        return solve(root, mini-10,maxi+10);
    }
};