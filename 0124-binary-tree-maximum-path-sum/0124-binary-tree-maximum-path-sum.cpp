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
    int maxi=INT_MIN;
    int solve(TreeNode* root){
        if(root==NULL){
            return 0;
        }
        
        int leftAns=0;
        int rightAns=0;// ye humnde value st keri h ki minmum can be only zero 
        // koi bhi negative vlaue hum apne path me include nhi karenge 
        // oth agar koi value negative hui toh uski jagah hum zero lelenge 
        
        
        leftAns=max(leftAns,solve(root->left));
        rightAns=max(rightAns, solve(root->right));
        
        // maxi value store kr vaale 
        int ans=(leftAns+rightAns)+root->val;
        maxi=max(maxi,ans);
        
        return max(leftAns, rightAns)+root->val;
        
        
    }
    int maxPathSum(TreeNode* root) {
        
        solve(root);
        
        return maxi;
    }
};