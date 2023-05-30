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
    
    int maxi=0;
    int largestRectangleArea(vector<int>& heights) {
        
        vector<int> next=nextsmall(heights);
        vector<int> prev=prevsmall(heights);
        
        int n=heights.size();
        for(int i=0;i<n;i++){
            int len=heights[i];
            
            if(next[i]==-1){
                next[i]=n;
            }
            
            int bth=next[i]-prev[i]-1;
            
            int area=len*bth;
            maxi=max(area,maxi);
            
            
        
        }
        
        
        
        return maxi;
    }
};