class Solution {
public:
    int search(vector<int>& arr, int target) {
        
        
        int low=0;
        int high=arr.size()-1;
        
        while(low <= high){
            int mid=(low+high)/2;
            
            if(arr[mid]==target){
                return mid;
            }
            if(arr[low] <= arr[mid]){ // matlab left part sorted hai 
                if(arr[low] <=target && target <arr[mid]){
                    high=mid-1;
                }else{
                    low=mid+1;
                }
            }else if(arr[low] >= arr[mid]){
                if(arr[mid]< target && target <=arr[high]){
                    low=mid+1;
                }else{
                    high=mid-1;
                }
            }
        }
        
        return -1;
    }
};