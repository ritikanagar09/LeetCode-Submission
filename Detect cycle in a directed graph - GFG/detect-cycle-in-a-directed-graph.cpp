//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    
    bool dfs(int node,vector<int> adj[], vector<int>&vis, vector<int>&pathvis ){
        
        pathvis[node]=1;
        vis[node]=1;
        
        
        for(auto adjnode:adj[node]){
            
            if(!vis[adjnode]){
                if(dfs(adjnode,adj,vis,pathvis)){
                    return true;// mark it here only true--> no need to visit aage 
                }
            }else if(pathvis[adjnode]){
                return true;
            }
        }
        
        
        // most importantly 
        // ye ek pura path tha .. jab humne ek node ko visit kiya 
        
        // jaane se pehele 
        
        // path vis ke values ko zero krke jao 
        
        pathvis[node]=0;
        
        return false;
        
    }
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        
        vector<int>vis(V,0);
        vector<int>path(V,0);
        
        for(int i=0;i<V;i++){
            if(!vis[i]){
                if(dfs(i,adj,vis,path)){
                    return true;
                }
            }
        }
        
        return false;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends