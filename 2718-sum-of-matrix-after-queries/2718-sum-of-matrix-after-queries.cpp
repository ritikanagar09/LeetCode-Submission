class Solution {
public:
    long long matrixSumQueries(int n, vector<vector<int>>& queries) {
        
        int N=queries.size();
        long long row=0;
        long long colm=0;
        long long sum=0;
        map<int,int>mpr,mpc;
        for(int i=N-1;i>=0;i--){
            
            int id=queries[i][1];
            
            if(queries[i][0]==0 && mpr[id]==0){// row
                // queries[i].push_back(colm);
                long long k=n-colm;
                long long ans=k*queries[i][2];
                sum+=ans;
                mpr[id]=1;
                row++;
                 if(row>n)
                    row=n;
            }else if(queries[i][0]==1 && mpc[id]==0){
                // queries[i].push_back(row);
                
                long long k=n-row;
                long long ans=k*queries[i][2];
                sum+=ans;
                mpc[id]=1;
                colm++;
                if(colm > n)
                    colm=n;
            }
        }
        
       
        
        return sum;
    }
};