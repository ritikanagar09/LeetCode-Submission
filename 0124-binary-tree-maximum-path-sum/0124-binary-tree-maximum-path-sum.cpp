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
    int solve(TreeNode* root, int &maxsum,vector<int>&path ){
       if(root==NULL){
            return 0;
        }
        
        
        int leftans=0;
        int rightans=0;
        
        leftans=max(leftans,solve(root->left,maxsum,path));
        rightans=max(rightans,solve(root->right,maxsum,path));
        
        int sum=root->val + leftans + rightans;
        
        maxsum=max(sum,maxsum);
        
        return max(leftans,rightans)+root->val;
    }
    int maxPathSum(TreeNode* root) {
        int maxsum=INT_MIN;
        vector<int>path;
        
        solve(root,maxsum,path);
        
        return maxsum;
    }
};