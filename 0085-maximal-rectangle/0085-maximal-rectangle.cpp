class Solution {
public:
    
    vector<int> nextsmall(vector<int>& heights){
        stack<int>st;
        int n=heights.size();
        vector<int>res(n);
        
        st.push(-1);
        for(int i=n-1;i>=0;i--){
            
            
            while(!st.empty() && (st.top() !=-1 && heights[st.top()]>= heights[i])){
                st.pop();
            }
            
            int ele=st.top();
            res[i]=ele;
            st.push(i);
            
        }
        
        return res;
    }
    
    
    vector<int> prevsmall(vector<int>& heights){
        stack<int>st;
        int n=heights.size();
        vector<int>res(n);
        
        st.push(-1);
        for(int i=0;i<n;i++){
            
            
            while(!st.empty() && (st.top() !=-1 && heights[st.top()]>= heights[i])){
                st.pop();
            }
            
            int ele=st.top();
            res[i]=ele;
            st.push(i);
            
        }
        
        return res;
    }
    
    int largestArea(vector<int>&heights){
        int n=heights.size();
        vector<int>next(n);
        next= nextsmall(heights);
        vector<int>prev(n);
        prev= prevsmall(heights);
        int maxArea=0;
        for(int i=0 ;i<n;i++){
            int length=heights[i];
            
            
            
            if(next[i]==-1){
                next[i]=n;
            }
            int breadth= next[i]-prev[i]-1;
            int area= length*breadth;
            maxArea=max(maxArea, area);
        }
        
        return maxArea;
        
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        
        int m=matrix.size();
        int n=matrix[0].size();
        vector<vector<int>>mat(m,vector<int>(n,0));
        
        for(int j=0;j<n;j++){
            char ch=matrix[0][j];
            if(ch=='1'){
                mat[0][j]=1;
            }
        }
        
        for(int i=1;i<m;i++){
            for(int j=0;j<n;j++){
                char ch=matrix[i][j];
                
                if(ch=='1'){
                    mat[i][j]=mat[i-1][j]+1;
                }
            }
        }
        
        int area=0;
        int maxarea=0;
        for(int i=0;i<m;i++){
            area=largestArea(mat[i]);
            maxarea=max(area,maxarea);
        }
        
        return maxarea;
    }
};