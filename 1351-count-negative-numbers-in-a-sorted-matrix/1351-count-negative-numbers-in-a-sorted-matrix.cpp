class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size(); 
        int cnt=0;
        for(int i=0;i<n;i++){
            // now 
            
            int l=0;
            int h=m-1;
            
            while(l<=h){
                int mid=(l+h)/2;
                if(grid[i][mid]>=0){
                    l=mid+1;
                }else{
                    h=mid-1;
                }
            }
            
            cout<<h<<endl;
            if(h!=m-1)
                cnt+=(m-l);
            
        }
        
        return cnt;
    }
};