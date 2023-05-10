class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
         int top=0,bottom=n-1, left=0,right=n-1;
        int step=1;
        // 4 directions are there
       
        int dir=1;
        vector<vector<int>>ans(n,vector<int>(n,0));
        while(top<=bottom && left<=right){
            
            if(dir==1){
                for(int i=left;i<=right;i++){
                    ans[top][i]=step;
                    step++;
                }
                
                dir=2;top++;
            }else if(dir==2){
                for(int i=top;i<=bottom;i++){
                    ans[i][right]=step;
                    step++;
                }
                
                dir=3;
                right--;
            }else if(dir==3){
                for(int i=right;i>=left;i--){
                    ans[bottom][i]=step;
                    step++;
                }
                
                dir=4;
                bottom--;
            }else if(dir==4){
                for(int i=bottom;i>=top;i--){
                    ans[i][left]=step;
                    step++;
                }
                
                dir=1;
               left++;
            }
        }
        
        return ans;
    }
};