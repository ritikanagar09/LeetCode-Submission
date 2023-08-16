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
    
    void minVal(TreeNode* root, int &mini){
        if(root==NULL){
            return;
        }
        
        
        mini=min(mini,root->val);
        
        minVal(root->left,mini);
        minVal(root->right,mini);
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        
        if(root==NULL){
            return NULL;
        }
        
        if(root->val==key){
            // sara delete ka logic likhna hume ynha
            
            // 0 nodes downside 
            
            if(root->left==NULL && root->right==NULL){
                delete(root);
                return NULL;
            }else if(root->left != NULL && root->right==NULL){
                
                // matlab ek side h dusri nhi h
                // jo h ushe store karva lo
                //or ush parent node ko delet kar do 
                TreeNode* temp= root->left;
                delete(root);
                return temp;
            }else if(root->left == NULL && root->right !=NULL){
                
                // matlab ek side h dusri nhi h
                // jo h ushe store karva lo
                //or ush parent node ko delet kar do 
                TreeNode* temp= root->right;
                delete(root);
                return temp;
            }else{
                
                // matlab dono childs h both left and right childs are there 
                
                // 2 options 
                // you can implement any of them 
                
                int mini=1e9;
                minVal(root->right,mini);
                root->val=mini;
                
                root->right=deleteNode(root->right,mini);
                return root;
                
                
                
                
            }
            
            
        }else if(root->val > key){
            root->left=deleteNode(root->left,key);
            return root;
        }else{
            root->right =deleteNode(root->right,key);
            return root;
        }
        
        
        
        
    }
};