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
    
    void solve(TreeNode* root, int targetSum, int &cnt, vector<int>&path){
        if(root==NULL){
            return;
        }
        
        path.push_back(root->val);
        solve(root->left, targetSum, cnt, path);
        
        solve(root->right, targetSum, cnt, path);
        
        long long int sum=0;
        for(int i=path.size()-1;i>=0;i--){
            sum+=path[i];
            if(sum==targetSum){
                cnt++;
            }
        }
        
        path.pop_back();
    }
    int pathSum(TreeNode* root, int targetSum) {
        
        
        int cnt=0;
        vector<int>path;
        solve(root, targetSum, cnt,path);
        
        return cnt;
    }
};