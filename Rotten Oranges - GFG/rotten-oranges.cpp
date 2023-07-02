//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    //Function to find minimum time required to rot all oranges. 
    int orangesRotting(vector<vector<int>>& grid) {
        // Code here
        
        int m=grid.size();
        int n=grid[0].size();
        
        queue<pair<int,int>>q;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==2){
                    q.push({i,j});
                }
            }
        }
        vector<vector<int>>vis(m, vector<int>(n,0));
        int time=-1;
        while(!q.empty()){
            int size=q.size();
            
            while(size--){
                int x=q.front().first;
                int y=q.front().second;
                
                q.pop();
                
                
                int dx[]={-1,0,1,0};
                int dy[]={0,1,0,-1};
                
                for(int i=0;i<4;i++){
                    int nx=x+dx[i];
                    int ny=y+dy[i];
                    
                    if(nx>=0 && nx<m && ny>=0 && ny<n && grid[nx][ny]==1 && !vis[nx][ny]){
                        grid[nx][ny]=2;
                        vis[nx][ny]=1;
                        q.push({nx,ny});
                    }
                }
            }
            
            time++;
        }
        
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    return -1;
                }
            }
        }
        
        
        return time;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.orangesRotting(grid);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends