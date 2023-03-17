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
      int indexOfelement(vector<int>& inorder,int x)
    {
        for(int i=0;i<inorder.size();i++)
        {
            if(inorder[i]==x)
            {
                return i;
            }
        }
        return -1;
    }
    
    
    TreeNode*construct(vector<int>& postorder, vector<int>& inorder,int low,int high,int &i)
    {

        if(low<0 || low>high || i<0)
        {
            return NULL;
        }
        
        int index=indexOfelement(inorder,postorder[i]);
        
        TreeNode*root=new TreeNode(inorder[index]);
        i--;
        root->right=construct(postorder,inorder,index+1,high,i);
       
        root->left=construct(postorder,inorder,low,index-1,i);
         // cout<<"low "<<low<<" index "<<index+1<<"  high. "<<high<<" i "<<i<<endl;
        
        
        return root;
     
    }
    
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int i=postorder.size()-1;
        
        return construct(postorder,inorder,0,inorder.size()-1,i);
    }
};