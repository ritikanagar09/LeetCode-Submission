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
    long int mod=1e9+7;
    vector<long>v;
    long solve(TreeNode* root){
        if(root==NULL){
            return 0;
        }
        if(root->left==NULL && root->right==NULL){
            return root->val;
        }
        
        long l=solve(root->left);
        long r= solve(root->right);
        
        long sum=l+r+root->val;
        
        v.push_back(sum);
        return sum;
        
    }
    int maxProduct(TreeNode* root) {
        long sum=solve(root);
        long maxi=0;
        
        for(int i=0;i<v.size()-1;i++){
            
           
                long first=v[i];
                long sec=sum-v[i];
                maxi=max(maxi,first*sec);
            
            
        }
        
          if(maxi==0){
            long k=sum/2;

            if(sum%2!=0){
                return 0;
            }
                return (k*k)%mod;
        }
        
        
        return maxi%mod;
    }
};