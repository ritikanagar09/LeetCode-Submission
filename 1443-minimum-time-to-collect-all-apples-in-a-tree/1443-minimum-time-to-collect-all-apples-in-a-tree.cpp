class Solution {
public:
    int solve(int node, vector<bool>&vis, vector<int>adj[], vector<bool>& hasApple){
       
        
        //base case 
        
        int time=0;
        vis[node]=true;
        
      
        for(auto it: adj[node]){
            if(!vis[it]){
                int ans=solve(it, vis,adj, hasApple);
                if(ans>0 || hasApple[it]){
                    time+=2+ans;
                }
               
            }
        }
        
     
        return time;
   
    }
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        
       
        vector<int>adj[n];
       
        for(int i=0;i<edges.size();i++){
            
            int u=edges[i][0];
            int v=edges[i][1];
           
            adj[u].push_back(v);
            adj[v].push_back(u);
           
        }
     
        vector<bool>vis(n,false);
        return solve(0, vis, adj, hasApple);
    }
};