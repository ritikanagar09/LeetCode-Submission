class Solution {
public:
    void dfs (vector<vector<int>>& graph, int src , int dest, vector<int>pth, vector<vector<int>>&ans ){
        if(src==dest){
            pth.push_back(dest);
            ans.push_back(pth);
            return;
        }
        
        pth.push_back(src);
        for(auto it:graph[src]){
            dfs(graph , it, dest, pth, ans);
            //pth.pop_back();
        }
        
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>>ans;
        vector<int>pth;
        int n=graph.size();
        dfs(graph, 0, n-1, pth,ans);
        return ans;
    }
};