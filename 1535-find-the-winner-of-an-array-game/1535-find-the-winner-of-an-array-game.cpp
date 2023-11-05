class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        int n=arr.size();
        
        int maxiElem=*max_element(arr.begin(),arr.end());
        
        if(k >= arr.size()){
            return maxiElem;
        }
        
        int curr_win=arr[0];
        int curr_streak=0;
        
        for(int i=1;i<n;i++){
            
            if(curr_win > arr[i]){
                curr_streak++;
            }else{
                // buddu swami
                
                curr_win=arr[i];
                curr_streak=1;
            }
            
            if(curr_streak ==k || curr_win==maxiElem){
                return curr_win;
            }
        }
        
        return -1;
    }
};