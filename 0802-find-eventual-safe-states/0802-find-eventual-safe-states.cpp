class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int v=graph.size();
        
        vector<int>adj[v];
        queue<int> q;
        vector<int>indeg(v,0);
        for(int i=0;i<v;i++){
            for(auto x: graph[i]){
                indeg[i]++;
                adj[x].push_back(i);
            }
        }
        
        vector<int>mark(v);
        for(int i=0;i<v;i++){
            if(indeg[i]==0){
                q.push(i);
                mark[i]=1;
            }
        }
        
        
        while(!q.empty()){
            int node=q.front();
            q.pop();
            
            
            for(auto adjnode:adj[node]){
                indeg[adjnode]--;
                if(indeg[adjnode]==0){
                    mark[adjnode]=1;
                    q.push(adjnode);
                }
            }
        }
        
        vector<int>ans;
        
        for(int i=0;i<v;i++){
            if(mark[i]==1){
                ans.push_back(i);
            }
        }
        
        return ans;
    }
};