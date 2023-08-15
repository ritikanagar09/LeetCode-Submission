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
class nodeVal{
    public:
    int maxnode, minnode, maxsize;
    
    nodeVal(int mini, int maxi, int size){ 
        maxnode=maxi;
        minnode=mini;
        maxsize=size;
    }
};

// ZARUZRU NHI H KI MASIZE BST ME MAX USM BHI PRESENT HO 
// SO FOR THAT KEEP A SEPERATE VARIABLE 










// MIN MAX SIZE 
class Solution {
public:
    int maxsum=0;
    nodeVal solve(TreeNode* root){
         if(root==NULL){
             // ULTA KRKE BHEJ DO 
             // SO THAT THEY WONT BE INCLUDED IN THE ANSSWR
            return nodeVal(INT_MAX,INT_MIN,0);
        }
        
        // postorder
        
        auto left=solve(root->left);
        auto right=solve(root->right);
        
        if(left.maxnode < root->val && root->val < right.minnode){
            // it is a BST 
            maxsum=max(maxsum, root->val+left.maxsize+right.maxsize);
            return nodeVal(min(root->val,left.minnode), max(root->val, right.maxnode), left.maxsize+right.maxsize+root->val);
        }
        
        
        // minimum node k liye -> miniumum value bhej rahe h 
        // maxiumu node k liye -> maximum value bhej rahe h
        return nodeVal(INT_MIN, INT_MAX, max(left.maxsize, right.maxsize));
        
    }
    int maxSumBST(TreeNode* root) {
       
        solve(root);
        
        if(maxsum<0){
            return 0;
        }
        
        return maxsum;
    }
};