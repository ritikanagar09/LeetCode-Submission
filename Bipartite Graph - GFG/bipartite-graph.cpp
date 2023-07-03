//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
private: 
    
    bool check(int src, int V,vector<int>adj[],vector<int>&vis ){
        
	    
	    queue<int>q;
	    
	    q.push(src);
	    vis[src]=1;
	    
	    while(!q.empty()){
	        int node=q.front();
	        q.pop();
	        int pcolr=vis[node];
	        
	        for(auto adjnode: adj[node]){
	            
	            if(vis[adjnode]==-1){
	                vis[adjnode] = !pcolr;
	                q.push(adjnode);
	            }else if(vis[adjnode]==vis[node]){
	                return false;
	            }
	        }
	    }
	    
	    return true;
    }
public:
	bool isBipartite(int V, vector<int>adj[]){
	    
	    vector<int>vis(V,-1);// -1 indicates no colr 
	    for(int i=0;i<V;i++){
	        
	        if(vis[i]==-1)
	        {
	            if(!check(i,V,adj,vis)){
	            return false;
	        }
	            
	        }
	    }
	    
	    return true;
	    
	}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		bool ans = obj.isBipartite(V, adj);    
		if(ans)cout << "1\n";
		else cout << "0\n";  
	}
	return 0;
}
// } Driver Code Ends