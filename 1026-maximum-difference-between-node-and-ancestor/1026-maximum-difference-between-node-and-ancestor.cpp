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
    int diff=0;
    int mini=INT_MAX;
    int maxi=INT_MIN;
    pair<int,int> solve(TreeNode* root){
        if(root==NULL){
            return {INT_MAX,INT_MIN};
        }
        if(root->left==NULL && root->right==NULL){
            // mini=min(mini,root->val);//4
            // maxi=max(maxi,root->val);//7
            return {root->val,root->val};
        }
        
        
        
        pair<int,int>l=solve(root->left);//3,3
        pair<int,int>r=solve(root->right);//0,0
        
        int nmin,nmax;
        nmin=min(l.first, r.first);//0
        nmax=max(l.second, r.second);//3
        int a= abs(root->val-nmin);
        int b= abs(root->val-nmax);
        int difi=max(a,b);
        diff=max(difi,diff);
        cout<<diff<<endl;
        nmin=min(nmin,root->val);
        nmax=max(nmax,root->val);
        //cout<<"return->"<<nmin<<" "<<nmax<<endl;
        return {nmin,nmax};
        
    }
    int maxAncestorDiff(TreeNode* root) {
        
        solve(root);
        return diff;
    }
};