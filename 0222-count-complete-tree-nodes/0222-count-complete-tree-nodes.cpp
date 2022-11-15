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
    
    int left(TreeNode* root){
        if(root==NULL){
            return 0;
        }
        
        // int ans=0;
        // if(root->left){
        //     ans=left(root->left);
        // }
        // return 1+ans;
        
        return 1+left(root->left);
    }
    
    
    int right(TreeNode* root){
        if(root==NULL){
            return 0;
        }
        
        // int ans=0;
        // if(root->right){
        //     ans=left(root->right);
        // }
        // return 1+ans;
        
        return 1+right(root->right);
    }

    int countNodes(TreeNode* root) {
        if(root==NULL)
        {
            return 0;
        }
        
        cout<<"root->val "<<root->val<<endl;
        int l,r=0;
        if(root->left){
            // l=1+height(root->left);//ush particular node ko bhi toh add karnge naa 
            l=1+left(root->left);
        }
        
        if(root->right){
            r=1+right(root->right);
        }
        
        if(l==r)
        {
            return pow(2,l)-1;
        }
        else
        {
            return 1+countNodes(root->left)+countNodes(root->right);
        }
    }
    
};