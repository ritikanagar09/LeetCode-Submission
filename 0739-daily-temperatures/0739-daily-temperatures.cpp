class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int>arr=temperatures;
        int n=temperatures.size();
        vector<int>res(n);
        
        stack<pair<int,int>>st;
        st.push({INT_MAX,INT_MAX});
        for(int i=n-1;i>=0;i--){
            
            while((st.top().first!=INT_MAX) && (st.top().first<=arr[i])){
                st.pop();
            }
            if(st.top().first==INT_MAX){
                res[i]=0;
            }else{
                res[i]=st.top().second-i;
                
            }
            st.push({arr[i],i});
            
        }
        
        
        
        return res;
    }
};