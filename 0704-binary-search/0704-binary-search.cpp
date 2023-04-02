class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low=0;
        int end=nums.size()-1;
        
        while(low<=end){
            int mid=low-(low-end)/2;
            
            if(nums[mid]>target){
                end=mid-1;
            }else if(nums[mid]<target){
                low=mid+1;
            }else{
                return mid;
            }
            
        }
        
        return -1;
        
        
    }
};