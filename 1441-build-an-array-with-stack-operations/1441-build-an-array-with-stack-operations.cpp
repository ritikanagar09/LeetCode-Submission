class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<int>vis(n+1,-1);
        
        int indx;
        for(int i=0;i<target.size();i++){
            indx=target[i];
            vis[indx]=1;
        }
        
        
        vector<string>ans;
        for(int i=1;i<=indx;i++){
            if(vis[i]==-1){
                ans.push_back("Push");
                ans.push_back("Pop");
            }else{
                ans.push_back("Push");
            }
        }
        
        return ans;
    }
};