class Solution {
public:
    vector<int> productExceptSelf(vector<int>& arr) {
        
        int n=arr.size();
       
        vector<int>ans(n,1);
        int prevMul=1;
        
        for(int i=1;i<n;i++){
            prevMul=prevMul*arr[i-1];
            ans[i]=prevMul;
        }
        
        
        
        int sufMul=1;
        
        for(int i= n-2;i>=0;i--){
            sufMul=sufMul*arr[i+1];
            ans[i]=ans[i]*sufMul;
        }
        
        
        
        return ans;
    }
};