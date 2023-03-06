class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int n=arr[arr.size()-1];
        
        for(int i=1;i<=100000;i++){
            
            bool flag=true;
            for(int j=0;j<arr.size();j++){
                if(i==arr[j]){
                    flag=false;
                }
            }
            
            if(flag){
                k--;
                if(k==0){
                    return i;
                }
            }
        }
        
        return -1;
    }
};