class Solution {
public:
    /*
    
    SC: O(N) + 0(N)-> FOR satck space and vis vector
    TC: o(N) + O(V+2E)
    
    
    
    */
    int n;
    void dfs(int node, vector<int>&vis,vector<vector<int>>& isConnected ){
        vis[node]=1;
        
        for(int j=0;j<n;j++){
            if(isConnected[node][j]){
                if(!vis[j]){
                    dfs(j,vis,isConnected);
                }
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        n=isConnected.size();
        vector<int>vis(n,0);
        int cnt=0;
        for(int i=0;i<n;i++){// visiitng all no connected components 
            if(!vis[i]){
                cnt++;
                dfs(i,vis,isConnected);
            }
            
            
        }
        
        return cnt;
    }
};