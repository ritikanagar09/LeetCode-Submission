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
    
    // MORRIS TRAVELLS
    vector<int> inorderTraversal(TreeNode* root) {
        if(root==NULL){
            return {};
        }
        vector<int>ans;
        
        TreeNode* curr=root;
        
        while(curr != NULL){
            // 2 cases can be there 
            
            if(curr->left==NULL){
                // ya toh left tree ho gaa hi nhi ush left tree kaa
                ans.push_back(curr->val);
                curr=curr->right;
            }else{
                
                // agar uska left part exit krta hai 
                
                // toh bhai jao left tree right most node par or 
                
                //usko point krvao apni current node par 
                
                // pointer to traverse to the rightmost node 
                
                
                
                
                
                
                // YHNHA KAR DI NAA MISTAKE
                
                // LEFT TREE KE RIGHTMOST NODE PAR JANA HAI
                // TreeNode* ptr=curr
                
                TreeNode* ptr=curr->left;
                
                
                
                
                
                
                while(ptr->right && ptr->right !=curr){ // jab tak ptr kaa right exit kar rha h and and aisa naa ho thread exxit kr rha ho or tum right most child ko dhundne jaa rahe ho
                    ptr=ptr->right;
                    
                }
                
                // now 2 cases will arrive 
                // yaa toh ptr kaa right NULL hoga 
                // yaa usme kuch hoga 
                
                
                // see ptr ke right ke baare you will get to know only when jab tak tum uske pass pohoch nhi jaate 
                // vahi jaa kar toh pta chalega 
                if(ptr->right==NULL){
                    ptr->right=curr;
                    // now thread lag gya 
                    // mujhe pta h mujhe knh avaaps aana h 
                    curr=curr->left;
                }else{
                    
                    
                    // matlab thread exit kar rha h
                    // that means we have already 
                    // been traversed the left part 
                    ptr->right=NULL;
                    ans.push_back(curr->val);
                    curr=curr->right;
                }
            }
        }
        
        
        return ans;
    }
};