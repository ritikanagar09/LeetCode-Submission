class Solution {
public:
    
    void dfs(int node,vector<vector<int>>& graph, vector<int>&vis ){
        vis[node]=1;
        
        for(int i=0;i<graph.size();i++){
            if(graph[node][i]==1 && !vis[i]){// matlab tum mere padosi ho 
                dfs(i,graph,vis);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& graph) {
        int n=graph.size();
        
        vector<int>vis(n,0);
        
        int cnt=0;
        for(int i=0;i<n;i++){
            
            if(!vis[i]){
                dfs(i,graph,vis);
                cnt++;
            }
            
            
        }
        
        return cnt;
    }
};