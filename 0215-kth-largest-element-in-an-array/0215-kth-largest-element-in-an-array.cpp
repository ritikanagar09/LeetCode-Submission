class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        multiset<int>st;
        for(auto it : nums ){
            st.insert(it);
        }
        
        vector<int>temp(st.size());
        int i=st.size()-1;
        for(auto it:st){
            temp[i]=it;
            i--;
        }
        
        // for(auto it:temp){
        //     cout<<it<<" ";
        // }
        
        cout<<endl;
        
        return temp[k-1];
        
        
        // return 0;
    }
};