//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    void dfs(int sr, int sc,vector<vector<int>>& image, vector<vector<int>>& ans, int ncolr, int incolr ){
        
        
        // pehle aate hi color kr diya 
        
        ans[sr][sc]=ncolr;
        
        int dx[4]={1,-1,0,0};
        int dy[4]={0,0,1,-1};
        int m=image.size();
        int n=image[0].size();
        for(int i=0;i<4;i++){
            int nr=sr+dx[i];
            int nc=sc+dy[i];
            
            if(nr>=0 && nc>=0 && nr<m && nc<n && image[nr][nc]==incolr && ans[nr][nc]!=ncolr)
                dfs(nr,nc,image, ans,ncolr,incolr);
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int inicolr=image[sr][sc];
        vector<vector<int>>ans=image;
        
        // jab bhi matrix hoti hai 
        //i dont think we require 
        
        dfs(sr,sc, image,ans,newColor,inicolr );
        
        
        return ans;
        
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>image(n, vector<int>(m,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cin >> image[i][j];
		}
		int sr, sc, newColor;
		cin >> sr >> sc >> newColor;
		Solution obj;
		vector<vector<int>> ans = obj.floodFill(image, sr, sc, newColor);
		for(auto i: ans){
			for(auto j: i)
				cout << j << " ";
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends