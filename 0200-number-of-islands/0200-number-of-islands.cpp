class Solution {
public:
    int m, n;
    
    void bfs(int i, int j,vector<vector<char>>& grid,vector<vector<int>>&vis ){
        vis[i][j]=1;
        
        // padosiyon ko visi krte hai 
        
        queue<pair<int,int>>q;
        q.push({i,j});
        
       while (!q.empty()) {
            auto current = q.front();
            q.pop();
            int x = current.first;
            int y = current.second;

            // Check all four directions
            int dx[] = {-1, 0, 1, 0};
            int dy[] = {0, 1, 0, -1};

            for (int k = 0; k < 4; k++) {
                int nx = x + dx[k];
                int ny = y + dy[k];

                if (nx >= 0 && nx < m && ny >= 0 && ny < n && grid[nx][ny] == '1' && !vis[nx][ny]) {
                    vis[nx][ny] = 1;
                    q.push({nx, ny});
                }
            }
        }
        
    }
    int numIslands(vector<vector<char>>& grid) {
       if (grid.empty() || grid[0].empty())
            return 0;

        queue<pair<int, int>> q;
         m = grid.size();
         n = grid[0].size();
        int islands = 0;
        vector<vector<int>> visited(m, vector<int>(n, 0));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (!visited[i][j] && grid[i][j] == '1') {
                    islands++;
                    // bfs(grid, i, j, visited, q, m, n);
                    bfs(i,j,grid,visited);
                }
            }
        }
        return islands;
        
    }
};