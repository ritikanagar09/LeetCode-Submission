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
    
    TreeNode* solve(vector<int>& nums, int start, int end){
        
        if(start > end){
            return NULL;
        }
        
        
        int rootIndx=(start+end)/2;
        TreeNode* root= new TreeNode(nums[rootIndx]);
        
        root->left=solve(nums,start,rootIndx-1);
        root->right=solve(nums,rootIndx+1,end);
        
        return root;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        
        
        return solve(nums,0,nums.size()-1);
    }
};