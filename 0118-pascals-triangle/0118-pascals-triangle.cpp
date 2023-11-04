class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        
        vector<vector<int>>ans;
        vector<int>v={1};
        ans.push_back(v);
        for(int i=2;i<=numRows;i++){
            vector<int>temp(i,1);
            for(int j=1;j<i-1;j++){
                cout<<i<<" "<<j<<endl;
                temp[j]=ans[i-2][j-1]+ans[i-2][j];
            }
            
            ans.push_back(temp);
        }
        
        return ans;
        
    }
};