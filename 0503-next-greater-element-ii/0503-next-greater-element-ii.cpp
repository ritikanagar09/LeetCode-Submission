class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& arr) {
        int n=arr.size();
        arr.resize(2*n);
        
        for(int i=n;i<2*n;i++){
            arr[i]=arr[i-n];
        }
        vector<int> ans(2*n);
        stack<int>st;
        
        st.push(INT_MAX);

        for(int i=(2*n)-1;i>=0;i--){
            int x=arr[i];
            while(!st.empty() && x>=st.top()){
                st.pop();
            }

            int y=st.top();
            st.push(x);
            if(y==INT_MAX){
                ans[i]=-1;
            }else{
                ans[i]=y;
            }
        }
        
        // return ans;
        
        vector<int>res(n);
        for(int i=0;i<n;i++){
            res[i]=ans[i];
        }
        
        return res;
        // return ans;
    }
        
};