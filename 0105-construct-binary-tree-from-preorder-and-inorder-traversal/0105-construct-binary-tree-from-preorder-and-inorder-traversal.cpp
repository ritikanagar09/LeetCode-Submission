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
    
    TreeNode* solve(vector<int>& preorder, vector<int>& inorder, int instart, int inEnd, int preStart, int preEnd, map<int,int>&inMap){
        if(preStart > preEnd || instart > inEnd){
            return NULL;
        }
        
        
        TreeNode* root= new TreeNode(preorder[preStart]);
        int rootIndx=inMap[root->val];
        
        int numLeft= rootIndx-instart;
        
        root->left=solve(preorder, inorder, instart, rootIndx-1, preStart+1, preStart+numLeft,inMap);
        
        root->right=solve(preorder, inorder, rootIndx+1, inEnd, preStart+numLeft+1, preEnd,inMap);
        
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        map<int,int>mpp;
        
        for(int i=0;i<inorder.size();i++){
            mpp[inorder[i]]=i;
        }
        
        return solve(preorder, inorder, 0,inorder.size()-1,0,inorder.size()-1,mpp );
    }
};