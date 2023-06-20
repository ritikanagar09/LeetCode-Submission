class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int low=0;
        int high=arr.size();
        
        while(low < high){ // no equal to condition
            int mid=(low+high)/2;
            
            if(arr[mid] < arr[mid+1]){
                // left part me h
                low=mid+1;
            }else{
                high=mid;
            }
        }
        
        return low;
    }
};