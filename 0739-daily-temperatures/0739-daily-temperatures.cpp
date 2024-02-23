class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        int n=temp.size();
        
        stack<pair<int,int>>st;
        vector<int>ans(n);
        st.push({INT_MAX,INT_MAX});
        
        for(int i=n-1;i>=0;i--){
            
            // ab jab tak nhi milta tab tak chlna hota hai
            while(st.top().first !=INT_MAX && st.top().first <= temp[i]){
                st.pop();
            }
            
            if(st.top().first==INT_MAX){
                ans[i]=0;
            }else{
                ans[i]=st.top().second - i;
            }
            
            st.push({temp[i],i});
        }
        
        return ans;
    }
};