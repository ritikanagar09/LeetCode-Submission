class Solution {
public:
    vector<int> productExceptSelf(vector<int>& arr) {
        
        int n=arr.size();
        vector<int>prevMul(n);
        
        prevMul[0]=1;
        
        for(int i=1;i<n;i++){
            prevMul[i]=prevMul[i-1]*arr[i-1];
        }
        
        
        vector<int>sufMul(n);
        sufMul[n-1]=1;
        
        for(int i= n-2;i>=0;i--){
            sufMul[i]=sufMul[i+1]*arr[i+1];
        }
        
        vector<int>ans(n);
        for(int i=0;i<n;i++){
            ans[i]=prevMul[i]*sufMul[i];
        }
        
        return ans;
    }
};