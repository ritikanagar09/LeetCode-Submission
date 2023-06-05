class Solution {
public:
    int n;
    bool isValid(int i,int j)
    {
        if(i<0 or j<0 or i>=n or j>=n)
            return false;
        return true;
    }
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        n=grid.size();
        vector<pair<int,int>>dir={{-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1}};
        if(grid[0][0]==1)
            return -1;
        if(n==1 and grid[0][0]==0)
            return 1;

        queue<pair<int,int>>q;
        q.push({0,0});

        int ans=1;
        while(!q.empty())
        {   
            int l=q.size();
            for(int i=0;i<l;i++)
            {
                int x=q.front().first;
                int y=q.front().second;
                q.pop();
                for(auto it:dir)
                {
                    int x1=x+it.first;
                    int y1=y+it.second;

                    if(x1==n-1 and y1==n-1 and grid[x1][y1]==0)
                        return ans+1;
                    if( isValid(x1,y1) and grid[x1][y1]==0)
                    {
                        grid[x1][y1]=1;
                        q.push({x1,y1});
                    }
                        
                    
                }
            }
            ans++;
        }
        return -1;
    }
};