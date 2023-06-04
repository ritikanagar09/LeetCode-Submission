class Solution {
public:
    int n;
    void dfs(int i, vector<int>&vis,vector<vector<int>>& isConnected ){
        vis[i]=1;
        
        
        for(int j=0;j<n;j++){
            if(isConnected[i][j]){
                if(!vis[j])
                    dfs(j,vis,isConnected);
            }
            
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        n=isConnected.size();
        vector<int>vis(n,0);
        int cnt=0;
        for(int i=0;i<n;i++){
            
            if(!vis[i]){
                cnt++;
                dfs(i,vis,isConnected);
            }
        }
        
        return cnt;
        
    }
};