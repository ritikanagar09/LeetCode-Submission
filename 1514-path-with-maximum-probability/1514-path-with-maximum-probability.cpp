class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        vector<pair<int,double>>adj[n];
        
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];
            
            double wt=succProb[i];
            
            adj[u].push_back({v,wt});
            adj[v].push_back({u,wt});
            
        }
        
        vector<double>dist(n,0.00);
        
        queue<int>q;
        
        q.push(start);
        dist[start]=1.0;
        
        while(!q.empty()){
            int pnode=q.front();
            q.pop();
            
            for(auto it:adj[pnode]){
                int cnode=it.first;
                double wt=it.second;
                if(dist[pnode] * wt > dist[cnode]){
                    dist[cnode] = dist[pnode]*wt;
                    q.push(cnode);
                }
            }
        }
        
        return dist[end];
    }
};