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
    
    void solve(TreeNode* root, map<int,int>&mpp){
        if(root==NULL){
            return;
        }
        
        mpp[root->val]++;
        
        solve(root->left,mpp);
        solve(root->right,mpp);
    }
    vector<int> findMode(TreeNode* root) {
        vector<int>ans;
        map<int, int>mpp;
        
        
        solve(root,mpp);
        
        int maxi=0;
        
        for(auto it:mpp){
            maxi=max(maxi,it.second);
        }
        
        for(auto it:mpp){
            if(it.second==maxi){
                ans.push_back(it.first);
            }
        }
        
        return ans;
        
        
        
    }
};