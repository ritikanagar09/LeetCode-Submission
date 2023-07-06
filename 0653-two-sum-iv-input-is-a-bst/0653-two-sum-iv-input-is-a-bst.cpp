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
    
    void solve(TreeNode* root, vector<int>&path, int k, bool &flag){
        
        if(root==NULL){
            return;
        }
        
       path.push_back(root->val);
        
        for(int i=0;i<path.size()-1;i++){
            if(path[i]+root->val==k){
                flag=true;
                return;
            }
        }
        
       solve(root->left,path,k,flag);
       solve(root->right,path,k,flag);
        
         
        
        // path.pop_back();
    }
    bool findTarget(TreeNode* root, int k) {
        
        
        bool flag=false;
        vector<int>path;
        solve(root,path, k,flag);
        
        return flag;
    }
};