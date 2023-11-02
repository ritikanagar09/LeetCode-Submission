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
    
    pair<int,int> solve(TreeNode* root, int &cnt){
        
        if(root==NULL){
            return {0,0};
        }
        
        pair<int,int> l=solve(root->left,cnt);
        pair<int,int>r=solve(root->right,cnt);
        
        int sum=l.first+r.first+root->val;
        int cntNode=l.second+r.second+1;
        
        int avg=sum/cntNode;
        if(avg==root->val){
            cnt++;
        }
        
        return {sum,cntNode};
    }
    int averageOfSubtree(TreeNode* root) {
        
        
        int cnt=0;
        solve(root, cnt);
        return cnt;
    }
};