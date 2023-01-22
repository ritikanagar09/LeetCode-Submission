class Solution {
public:
    vector<int>v;
    void inorder(TreeNode* root){
        if(root==NULL) return;
        inorder(root->left);
        v.push_back(root->val);
        inorder(root->right);
    }
    int bs_min(int a){
        int start=0, end=v.size()-1;
        int ans=-1;
        while(start<=end){
            int mid=start + (end-start)/2;
            if(v[mid]<=a){
                ans=v[mid];
                start=mid+1;
            }
            else if(v[mid]> a){
                end=mid-1;
            }
        }
        return ans;
    }
    int bs_max(int a){
        int start=0, end=v.size()-1;
        int ans=-1;
        while(start<=end){
            int mid=start + (end-start)/2;
            if(v[mid]>=a){
                ans=v[mid];
                end=mid-1;
            }
            else if(v[mid]< a){
                start=mid+1;
            }
        }
        return ans;
    }
    vector<vector<int>> closestNodes(TreeNode* root, vector<int>& queries) {
        inorder(root);   //O(N)
        vector<vector<int>>ans;
        for(auto &i: queries){  //O(n(log(n))
            int min=-1,max=-1;
            min=bs_min(i);
            max=bs_max(i);
            vector<int>temp;
            temp.push_back(min);
            temp.push_back(max);
            ans.push_back(temp);
        }
        return ans;
    }
};