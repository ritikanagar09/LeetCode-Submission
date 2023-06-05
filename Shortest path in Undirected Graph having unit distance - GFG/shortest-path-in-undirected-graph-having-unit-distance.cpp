//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    vector<int> shortestPath(vector<vector<int>>& edges, int N,int M, int src){
         vector<int>adj[N];
         
         
        //   for(auto it : edges) {
        //     adj[it[0]].push_back(it[1]); 
        //     adj[it[1]].push_back(it[0]); 
        // }
         
         for(int i=0;i<M;i++){
             int u=edges[i][0];
             int v=edges[i][1];
             adj[u].push_back(v);
             adj[v].push_back(u);// undirected graph 
         }
         
        //  int dist[N];
        //  for(int i=0;i<N;i++){
        //      dist[i]=1e8;
        //  }
         
         
         queue<int>q;
        //  q.push(src);
         
         
        vector<int>dist(N,1e8);
        dist[src]=0;
         
        // while(!q.empty()){
        //     int node=q.front();
        //     q.pop();
        //     for(auto adjnode :adj[node]){
                
        //         if(dist[node]+1<dist[adjnode]){
        //             dist[adjnode]=dist[node]+1;
        //             //irf usnhi node ko firrse daal rahe h jine updation hua h
        //             q.push(adjnode);
        //         }
                
                
        //     }
        // }
        
        
        q.push(src); 
        while(!q.empty()) {
            int node = q.front(); 
            q.pop(); 
            for(auto it : adj[node]) {
                if(dist[node] + 1 < dist[it]) {
                    dist[it] = 1 + dist[node]; 
                    q.push(it); 
                }
            }
        }
        
        for(int i=0;i<N;i++){
            if(dist[i]==1e8){
                dist[i]=-1;
            }
        }
        
        return dist;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m; cin >> n >> m;
        vector<vector<int>> edges;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for(int j=0; j<2; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }

        int src; cin >> src;

        Solution obj;

        vector<int> res = obj.shortestPath(edges, n, m, src);

        for (auto x : res){
            cout<<x<<" ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends