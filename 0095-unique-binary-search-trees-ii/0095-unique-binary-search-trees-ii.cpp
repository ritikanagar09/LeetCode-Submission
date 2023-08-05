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
    
    vector<TreeNode*> solve(int start, int end){
        
        
        if(start > end){
            return {NULL};
        }
        
        if(start==end){
            return {new TreeNode(start)};
        }
        
        
        
        vector<TreeNode*>ans;
        for(int i=start;i<=end;i++){
            
            vector<TreeNode*>left_BST= solve(start,i-1); // isme saaare left BST aa gye hai 
            vector<TreeNode*>right_BST= solve(i+1,end);
            
            
            for(int k=0;k<left_BST.size();k++){
                for(int j=0;j<right_BST.size();j++){
                    TreeNode* root= new TreeNode(i);
                    root->left=left_BST[k];
                    root->right=right_BST[j];
                    
                    ans.push_back(root);
                }
            }
            
        }
        
        return ans;
    }
    vector<TreeNode*> generateTrees(int n) {
        
        
        return solve(1,n);
        
    }
};