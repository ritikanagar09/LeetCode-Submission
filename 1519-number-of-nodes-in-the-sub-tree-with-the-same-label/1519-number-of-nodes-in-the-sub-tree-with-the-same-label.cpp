class Solution {
    vector<int> res;
    vector<int> dfs(vector<int> adj[], int i, string& labels, int prev) {
        vector<int> v(26, 0);
        for (auto j: adj[i]) {
            if (j != prev) {
                vector<int> temp = dfs(adj, j, labels, i);
                for (int i=0; i<26; i++) {
                    v[i] += temp[i];
                }
            }
        }
        v[labels[i]-'a']++;
        res[i] = v[labels[i]-'a'];
        return v;
    }
public:
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        res = vector<int>(n, 0);
        vector<int>adj[n];
        
        
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];
            
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        dfs(adj,0,labels,-1);

   
        return res;
    }
};