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
    int maxLevelSum(TreeNode* root) {
        
        if(root==NULL){
            return 0;
        }
        
        if(root->left==NULL && root->right==NULL){
            return 1;
        }
        queue<TreeNode*>q;
        
        
        q.push(root);
        int level=1;
        int cnt=1;
        long long int sum=root->val;
        while(!q.empty()){
            int size=q.size();
            long long int lsum=0;
            while(size--){
                TreeNode* front=q.front();
                q.pop();
                lsum+=front->val;
                
                if(front->left){
                    q.push(front->left);
                }
                
                if(front->right){
                    q.push(front->right);
                }
                
            }
            
            if(lsum>sum){
                sum=lsum;
                level=cnt;
            }
            
            cnt++;
            
            
        }
        
        
        return level;
    }
};