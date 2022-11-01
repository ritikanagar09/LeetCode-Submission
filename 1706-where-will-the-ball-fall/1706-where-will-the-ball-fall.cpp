class Solution {
public:
    vector<int> findBall(vector<vector<int>>& v) {
        int m = v.size();
        int n = v[0].size();
        vector<int> ans;
        if((m == 1 && n == 1) || n == 1){
            return {-1};
        }
        for(int i=0;i<n;i++){
            int row = 0, col = i;
            while(row < m && col < n){
                if(col == 0){
                    if(v[row][col] == 1 && v[row][col+1] == 1){
                        row++;col++;
                    }else{
                        ans.push_back(-1);
                        break;
                    }
                }else if(col == n-1){
                    if(v[row][col] == -1 && v[row][col-1] == -1){
                        row++,col--;
                    }else{
                        ans.push_back(-1);
                        break;
                    }
                }else{
                    if(v[row][col] == 1 && v[row][col+1] == 1){
                        row++;col++;
                    }else if(v[row][col] == -1 && v[row][col-1] == -1){
                        row++,col--;
                    }else{
                        ans.push_back(-1);
                        break;
                    }
                }
            }
            if(row >= m){
                ans.push_back(col);
            }
        }
        return ans;
    }
};