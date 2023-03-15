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
    void solve(TreeNode* root, int &totsum, int sum){
        if(root->left==NULL && root->right==NULL){
            int k=sum*10 +root->val;
            sum=k;
            cout<<sum<<endl;
            totsum+=sum;
            
            return;
        }
        
        
        int k=sum*10 +root->val;
        sum=k;
        
        if(root->left)
            solve(root->left, totsum, sum);
        if(root->right)
            solve(root->right, totsum, sum);
    }
    int sumNumbers(TreeNode* root) {
        
        int totsum=0;
        int sum=0;
        solve(root, totsum ,sum);
        return totsum;
    }
};