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
    vector<int>res;
    int maxfreq=0,currfreq=0,precursor=INT_MIN;
    void solve(TreeNode*root){
        if(root==NULL){
            return;
        }
        
        solve(root->left);
        
        if(root->val==precursor)
            currfreq++;
        else 
            currfreq=1;
        
        if(currfreq > maxfreq){
            res.clear();
            res.push_back(root->val);
            maxfreq=currfreq;
        }else if(currfreq==maxfreq){
            res.push_back(root->val);
        }
        
        precursor=root->val;
        
        
        solve(root->right);
    }
    vector<int> findMode(TreeNode* root) {
        
        solve(root);
        return res;
    }
};