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
    int maxi(TreeNode* root){
        if(root==NULL){
            return -1;
        }
        
        int x=maxi(root->left);
        int y=maxi(root->right);
        
        return max(root->val,max(x,y));
    }
    
    int mini(TreeNode* root){
        if(root==NULL){
            return INT_MAX;
        }
        
        int x=mini(root->left);
        int y=mini(root->right);
        
        return min(root->val,min(x,y));
    }
    int solve(TreeNode* root){
        if(root==NULL || (root->left==NULL && root->right==NULL)){
            return 1000000;
        }
        
        int k=maxi(root->left);
        int a=INT_MAX;
        if(k!=-1)
            a=abs(root->val-k);
        int b=abs(root->val-mini(root->right));
        
        int x=solve(root->left);
        int y=solve(root->right);
        
        cout<<root->val<<" "<<a<<" "<<b<<" "<<x<<" "<<y<<endl;
        return min(x,min(y,min(a,b)));
        
        
    }
    int minDiffInBST(TreeNode* root) {
        
        return solve(root);
    }
};