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
    int sumP(TreeNode* root, int &tar, long long int curr){
        if(!root){
            return 0;
        }
        
        long long int pre=curr+root->val;
        
        return (pre==tar) + sumP(root->left,tar,pre)+sumP(root->right,tar,pre);
    }
    int pathSum(TreeNode* root, int targetSum) {
        
        if(!root){
            return 0;
        }
        
        int rootcnt=sumP(root,targetSum, 0);
        int left=pathSum(root->left,targetSum);
        int right=pathSum(root->right,targetSum);
        
        return rootcnt+left+right;
    }
};