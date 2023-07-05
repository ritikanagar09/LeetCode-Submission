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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        
        
        map<int,map<int,multiset<int>>>mpp;// we are using vertor kyunki ek hi lvl or hd par more than one nodes ho skti h
        queue<pair<TreeNode*,pair<int,int>>>q;
        
        q.push({root,{0,0}});
        
        while(!q.empty()){
            TreeNode* front=q.front().first;
            
            
            int hd=q.front().second.first;
            int lvl=q.front().second.second;
            q.pop();
            mpp[hd][lvl].insert(front->val);
            
            if(front->left){
                q.push({front->left,{hd-1,lvl+1}});
            }
            
            if(front->right){
                q.push({front->right,{hd+1,lvl+1}});
            }
            
        }
        
        vector<vector<int>>ans;
        for(auto it:mpp){
            // ye vector ynhi lagega 
            // kyunki -> ek particular hd ke liye mutliple levl par nodes ho skti h
            vector<int>temp;
            
            for(auto j:it.second){
                
                for(auto k:j.second){
                    temp.push_back(k);
                }
                
            }
            ans.push_back(temp);
        }
        
        return ans;
    }
};