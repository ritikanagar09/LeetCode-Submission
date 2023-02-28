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
    void ff(TreeNode* root,vector<int>&help){
        if(root == NULL){
            help.push_back(-3000);
            return;
        }
        help.push_back(root->val);
        ff(root->left,help);
        ff(root->right,help);
    }
    void f(TreeNode*root,map<vector<int>,int>&mp,vector<TreeNode*>&ans){
        if(root==NULL){
            return;
        }
        vector<int>help;
        ff(root,help);
       
        if(mp.find(help)!= mp.end() && mp[help]==1){
            ans.push_back(root);
            mp[help]++;
        }
        else{
         
            mp[help]++;
        }
        if(root->left != NULL){
        f(root->left , mp, ans);
        }
        if(root->right != NULL){
        f(root->right , mp, ans);
        }
    }
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        if(root==NULL){
            return {};
        }
        map<vector<int>,int>mp;
        vector<TreeNode*>ans;
        if(root->left != NULL){
        f(root->left , mp, ans);
        }
        if(root->right != NULL){
        f(root->right , mp, ans);
        }
        return ans;   
    }
};

