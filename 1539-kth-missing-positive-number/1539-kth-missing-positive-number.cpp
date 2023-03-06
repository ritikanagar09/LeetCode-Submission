class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        
        int cnt=1;
        
        int i=0;
        while(i<arr.size()){
            cout<<i<<" "<<arr[i]<<" "<<cnt<<" "<<k<<endl;
            if(cnt==arr[i]){
                i++;
                
            }else{
                k--;
            }
            
            if(k==0){
                return cnt;
            }
            cnt++;
        }
        
        return cnt+k-1;
    }
};