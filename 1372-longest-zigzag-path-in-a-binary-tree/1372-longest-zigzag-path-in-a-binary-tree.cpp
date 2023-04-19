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
    int maxsteps=0;
    void solve(TreeNode* root, int steps, bool left){
        if(root==NULL){
            return;
        }
        
        maxsteps=max(maxsteps, steps);
        
        if(left){
            solve(root->left, steps+1, false);
            // doosra option bhi expore karnge hum
            solve(root->right, 1, true);// 1 bcoz we are now exploring a new path
        }else{
            solve(root->right, steps+1, true);
            solve(root->left,1, false);
        }
        
        
    }
    int longestZigZag(TreeNode* root) {
        // we will explore both the possibilties 
       solve(root, 0, true);
        solve(root,0,false);
        
        return maxsteps;
    }
};