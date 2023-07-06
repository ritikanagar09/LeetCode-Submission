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
    
    pair<int,int> solve(TreeNode* root, int &maxi){
        
        if(root==NULL){
            return {1e9,-1e9};
        }
        
        if(root->left==NULL && root->right==NULL){
            return {root->val,root->val};
        }
        
        
        pair<int,int> leftAns=solve(root->left,maxi);
        pair<int,int> rightAns=solve(root->right,maxi);
        
        int minval=min(leftAns.first, rightAns.first);
        int maxval=max(leftAns.second, rightAns.second);
        
        int ans=max(abs(maxval-root->val), abs(minval-root->val));
        
        if(ans>maxi){
            maxi=ans;
        }
        
        minval=min(minval, root->val);
        maxval=max(maxval,root->val );
        
        return {minval,maxval};
        
    }
    int maxAncestorDiff(TreeNode* root) {
        
        int maxi=0;
        solve(root,maxi);
        
        return maxi;
    }
};