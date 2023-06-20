class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int low=0;
        int high=nums.size()-1;
        
        int num;
        
        while(low<high){
            int mid=(low+high)/2;
            num=mid%2==0 ? mid+1:mid-1;
            
            if(nums[mid]==nums[num]){// bhadaiyaan aap left par me hi ho ..par apna left danda dhudne low ko aage bdha do 
                low=mid+1;
                
            }else{
                high=mid;
            }
        }
        
        return nums[low];
    }
};