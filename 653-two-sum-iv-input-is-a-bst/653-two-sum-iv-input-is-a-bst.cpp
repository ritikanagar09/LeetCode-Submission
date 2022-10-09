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
    
    void solve(TreeNode* root, vector<int>&ans){
        if(root==NULL){
            return;
        }
        
        solve(root->left, ans);
        ans.push_back(root->val);
        solve(root->right, ans);
        
    }
    
    bool findTarget(TreeNode* root, int k) {
        
        vector<int>ans;
        solve(root,ans);
        int low=0;
        int high=ans.size()-1;
        
        
//         for(int i=0;i<ans.size();i++){
            
//             int low=i+1;
//             int high=ans.size()-1;
            
//             while(low<high){
//                 int mid= low+ (high-low)/2;
                
//                 if(ans[i]+ans[mid] < k){
//                     low++;
//                 }else if(ans[i]+ans[mid] > k){
//                     high--;
//                 }else{
                    
//                     return true;
                    
//                 }
                
//             }
            
            
//         }
        
        while(low<high){
                
                
                if(ans[low]+ans[high] < k){
                    low++;
                }else if(ans[low]+ans[high] > k){
                    high--;
                }else{
                    
                    return true;
                    
                }
                
            }
        
        
        return false;
        
       
    }
};