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
        // hum ynha par level vise chl rahe hai 
        // toh quueue use karenge 
        // har node ko ek index de rhe hai 
        // iske vajag each node will be resent a number line 
        // hence we can simple find th enumber of node sbetween two nodes
        
        queue<pair<TreeNode*,ll>>q;
        q.push({root,0});
        
        ll ans=0;
        
        while(!q.empty()){
            
            // ush particular level k sari ndeos ko index se naam krnge 
            int n=q.size();
            
            // abhi tak queue me jo bhi padha tha 
            // hum vo dekh rahe hai 
            // unke liye calculations karne ki koshish kar rahe h
            ll low=q.front().second;
            ll high=q.back().second;
            
            ans=max(ans, high-low+1);
            
            while(n--){
                TreeNode* front=q.front().first;
                ll indx=q.front().second;
                q.pop();
                
                if(front->left){
                    q.push({front->left,2*indx+1});
                }
                
                if(front->right){
                    q.push({front->right,2*indx+2});
                }
            }
            
            
        }
        
        return ans;
    }
};