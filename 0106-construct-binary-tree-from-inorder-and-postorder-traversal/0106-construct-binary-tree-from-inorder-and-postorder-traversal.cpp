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
    
    TreeNode* solve(vector<int>& inorder, vector<int>& postorder, int inst, int inend, int pst, int pend , map<int,int>&mpp){
        
        
        if(inst > inend || pst > pend){return NULL;}
        
        
        
        TreeNode* root=new TreeNode(postorder[pend]);
        
        int indx = mpp[root->val];
        
        int numleft= indx-inst; // number of nodes of left subtree
        
        root->left=solve(inorder, postorder,inst, indx-1,pst, pst+numleft-1, mpp );
        
        root->right=solve(inorder, postorder,indx+1, inend,pst+numleft,pend-1, mpp );
        
        return root;
        
        
    }
        
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        
        int n=inorder.size();
        map<int,int>mpp;
        for(int i=0;i<n;i++){
            mpp[inorder[i]]=i;
        }
        
        return solve(inorder, postorder,0,n-1,0,n-1,mpp);
    }
};