class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<int>vis(n,0);
        
        for(auto i:edges){
            vis[i[1]]++;
        }
        
        
        vector<int>ans;
        for(int i=0;i<vis.size();i++){
            if(vis[i]==0){
                ans.push_back(i);
            }
        }
        
        return ans;
        
    }
};