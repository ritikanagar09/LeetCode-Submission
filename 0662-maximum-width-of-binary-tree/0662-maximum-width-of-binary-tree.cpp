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
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*,long long int>>q;
        int maxwidth=0;
        q.push({root,0});
        while(!q.empty()){
            int size=q.size();
            
            long long int nmin=q.front().second;
            int first=0;
            int last=0;
            
            for(int i=0;i<size;i++){
                long long int currid=q.front().second-nmin;
                TreeNode* front=q.front().first;
                
                q.pop();
                
                if(i==0)
                    first=currid;
                if(i==size-1)
                    last=currid;
                
                if(front->left)
                    q.push({front->left,2*currid+1});
                if(front->right)
                    q.push({front->right,2*currid+2});
            }
            
            int width=last-first+1;
            maxwidth=max(width,maxwidth);
            
        }
        
        return maxwidth;
    }
};