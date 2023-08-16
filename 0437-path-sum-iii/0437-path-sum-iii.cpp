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
    
    void solve(TreeNode* root, vector<int>&path, int tar, int &cnt){
        if(root==NULL){
            return ;
        }
        
        
        path.push_back(root->val);
        long long sum=0;
        for(int i=path.size()-1;i>=0;i--){
            sum+=path[i];
            if(sum==tar){
                cnt++;
            }
        }
        
        solve(root->left,path,tar,cnt);
        solve(root->right,path,tar,cnt);
        
        path.pop_back();
        
        
    }
    int pathSum(TreeNode* root, int targetSum) {
        
        
        vector<int>path;
        int cnt=0;
         solve(root,path,targetSum, cnt);
        
        return cnt;
        
    }
};