class Solution {
public:
    int maximalRectangle(vector<vector<char>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        
        int maxi=0;
        vector<vector<int>>A(n, vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                A[i][j]=mat[i][j]-'0';
            }
        }
        
        
        
        
//         for(int i=0;i<n;i++){
//             for(int j=0;j<m;j++){
//                 if(matrix[i][j]==1){
//                     matrix[i][j]+=matrix[i-1][j];
//                 }
//             }
//         }
        
        
//         for(int i=0;i<n;i++){
            
//             stack<int>l;
            
//             vector<int>prev(m);
//             for(int j=0;j<m;j++){
//                 while(!l.empty() && matrix[i][l.top()]>=matrix[i][j]){
//                     l.pop();
//                 }
                
//                 prev[j]=(!l.empty()) ? l.top():-1;
//                 l.push(j);
//             }
            
            
//             stack<int>r;
            
//             vector<int>next(m);
//             for(int j=m-1;j>=0;j--){
//                 while(!r.empty() && matrix[i][r.top()]>=matrix[i][j]){
//                     r.pop();
//                 }
                
//                 next[j]=(!r.empty()) ? r.top():m;// ye acha case handle hua hai
//                 r.push(j);
//             }
            
//             // finaly caluclting max area
            
//             for(int j=0;j<m;j++){
//                 maxi=max(maxi, matrix[i][j]*(next[j]-prev[j]-1));
//             }
            
            
//         }
        
//         return maxi;
        
        
        int maxar = 0;
    //building histogram for each row upto that row 
    for (int i = 1; i < n; i++)
        for (int j = 0; j < m; j++)
            if (A[i][j])    A[i][j] += A[i-1][j];
    //calculating max area of histogram for each row
    for (int i = 0; i < n; i++) {
        stack<int> l, r;
        vector<int> lv(m), rv(m);
        //previous smaller element
        for (int j = 0; j < m; j++) {
            while (!l.empty() && A[i][l.top()] >= A[i][j])  l.pop();
            lv[j] = (!l.empty()) ? l.top() : -1;
            l.push(j);
        }
        //next smaller element
        for (int j = m-1; j >= 0; j--) {
            while (!r.empty() && A[i][r.top()] >= A[i][j])  r.pop();
            rv[j] = (!r.empty()) ? r.top() : m;
            r.push(j);
        }
        //max area calculation
        for (int j = 0; j < m; j++)
            maxar = max(maxar, A[i][j] * (rv[j] - lv[j] - 1));
    }
    return maxar;
    }
};