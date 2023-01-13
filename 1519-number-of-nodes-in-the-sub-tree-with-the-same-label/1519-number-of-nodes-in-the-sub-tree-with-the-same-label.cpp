class Solution {
    vector<int> res;
    vector<int> dfs(vector<vector<int>>& adj, int i, string& labels, int prev) {
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
        vector<vector<int>> adj(n);
        for (auto i: edges) {
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        dfs(adj, 0, labels, -1);
        return res;
    }
};