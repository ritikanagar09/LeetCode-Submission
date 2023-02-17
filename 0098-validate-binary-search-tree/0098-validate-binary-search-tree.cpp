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
    bool isBST(TreeNode* root, TreeNode* mini, TreeNode* maxi){
        if(root==NULL){
            return true;// we are asumming ki NULL node humesha satify karegi condition
        }
        
        if((mini && root->val<=mini->val) || (maxi&& root->val>=maxi->val)){
            return false;
        }
        bool left=isBST(root->left,mini,root);
        bool right=isBST(root->right,root,maxi);
        return left && right;
            // agar uppar vaali condition hi fail hp gyi toh return false;
        
    }
    bool isValidBST(TreeNode* root) {
        TreeNode* mini=NULL;
        TreeNode* maxi=NULL;//THINGS WERE NOT GETTING HANDLED WITH INT_MIN AND INT_MAx
        if(root->left==NULL && root->right==NULL){
            return true;//single node always satisy
        }
        return isBST(root,mini,maxi);
    }
};