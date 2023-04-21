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
    typedef unsigned long long ll;
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*,ll>>q;
        q.push({root,0});
        
        ll res=0;
        while(!q.empty()){
            int n=q.size();
            int l=q.front().second;
            int r=q.back().second;
            ll ans=r-l+1;
            res=max(res,ans);
            
            while(n--){
                TreeNode* front=q.front().first;
                ll indx=q.front().second;
                q.pop();
                
                if(front->left){
                    q.push({front->left,2*indx+1});
                }
                
                if(front->right){
                    q.push({front->right, 2*indx+2});
                }
            }
        }
        
        return res;
    }
};